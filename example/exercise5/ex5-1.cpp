#include <vector>
#include <random>
#include <iostream>
#include <cmath>

using namespace std;

enum State{
    S = 0, I, R, NUM_STATE
};

void Init(vector<vector<int> >& world, int init_i, mt19937& mt){
    int h = world.size();
    int w = world[0].size();  
    uniform_int_distribution<> rand_w(0, w-1);
    uniform_int_distribution<> rand_h(0, h-1);

    int count = 0;
    while(true){
        int tmp_x = rand_h(mt);
        int tmp_y = rand_w(mt);
        if(world[tmp_x][tmp_y] == S){
            world[tmp_x][tmp_y] = I;
            count++;
        }
        if(count == init_i){
            break;
        }        
    }
}

void PrintStateCount(vector<int>& state_count){
    cout << state_count[S] << "," << state_count[I] << "," << state_count[R] << endl;
}

int CountNeighborInfectious(vector<vector<int> >& world, int i, int j){
    int h = world.size();
    int w = world[0].size();   

    int sum = 0;
    for(int di = -1; di <=1; di++){
        for(int dj = -1; dj <=1; dj++){
            if(di == 0 && dj == 0){
                continue;
            }
            if(i + di < 0 || j + dj < 0 || i + di >= h || j + dj >= w){
                continue;
            }else{
                if(world[i+di][j+dj] == I){
                    sum++;
                }     
            }
        }
    }
    return sum;
}

void UpdateWorld(vector<vector<int> >& new_world, double th, int i, int j, int s1, int s2, mt19937& mt){
    //static変数は最初に関数を呼んだ時のみ初期化され、2回目以降は情報が保持される。
    static uniform_real_distribution<double> dist(0.0, 1.0);
    double r = dist(mt);
    if(r < th){
        new_world[i][j] = s2;
    }else{
        new_world[i][j] = s1;
    }
}

void Simulation(vector<vector<int> >& world, vector<int>& state_count, double beta, double gamma, mt19937& mt){
    int h = world.size();
    int w = world[0].size();    
    vector<vector<int> > new_world(h, vector<int>(w, 0));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int s = world[i][j];

            if(s == S){
                int nI = CountNeighborInfectious(world, i, j);          
                double th = 1 - pow((1 - beta), nI);
                UpdateWorld(new_world, th, i, j, S, I, mt);
            }else if(s == I){                
                UpdateWorld(new_world, gamma, i, j, I, R, mt);
            }else{
                new_world[i][j] = R;
            }
        }
    }
    state_count.assign(state_count.size(), 0);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            world[i][j] = new_world[i][j];
            state_count[world[i][j]]++;
        }
    }
}

int main(void){
    //設定の初期化
    int w = 50, h = 50;
    vector<vector<int>> world(h, vector<int>(w, 0));

    random_device rnd;
    mt19937 mt(rnd());    
    vector<int> state_count(NUM_STATE, 0);    
    int init_i = 2;
    

    Init(world, init_i, mt);
    state_count[S] = w * h - init_i;
    state_count[I] = init_i;

    double beta = 0.3, gamma = 0.05;
    PrintStateCount(state_count);
    while(state_count[I] != 0){        
        Simulation(world, state_count, beta, gamma, mt);
        PrintStateCount(state_count);
    }
}