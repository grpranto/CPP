#include<bits/stdc++.h>
#include<windows.h>
#define SIZE 5
#define Size 4
using namespace std;

int matrix[Size][Size] = {0};
vector <int> finalPath;
int arr[SIZE];
long long current, next, E;
float num, prob;

void cost();
void solution();
void random();
void state();
void PATH();
void finalSolution();
void begiN();

int main(){
    begiN();
    cost();

    state();
    PATH();

    cout << "Cost Matrix : " << endl << endl;
    for(int i=0; i<Size; i++){
        for(int j=0; j<Size; j++){
            cout << "[" << i << "][" << j << "] = " << matrix[i][j] << endl;
        }
        putchar('\n');
    }

    cout << "Current state : ";
    solution();

    current = matrix[0][0] + matrix[0][arr[1]] + matrix[arr[1]][arr[2]]+ matrix[arr[2]][arr[3]] + matrix[arr[3]][0];
    cout << "Cost Of Current state: " << current << endl << endl;

    for(int T=100; T>=1; T--){
        cout << "----------------------------------------------------------------------------------------" << endl << endl;
        cout << "\t\t---------------------" << endl;
        cout << "\t\t| TEMPERATURE = " << T << "  |"<< endl;
        cout << "\t\t---------------------" << endl << endl;
        cout << "Randomly selected neighbor state : ";
        state();
        solution();
        cout << endl;
        next = matrix[0][0] + matrix[0][arr[1]] + matrix[arr[1]][arr[2]]+ matrix[arr[2]][arr[3]] + matrix[arr[3]][0];

        E = current - next;
        cout << "Cost of current state was: " << current << endl;
        cout << "Cost of neighbor state is : " << next << endl;
        cout << endl;
        if(E > 0){

            current = next;
            cout << "As the neighbor state value is less than current state value, so the neighbor state is assigned as current state" << endl;
            cout << "Now cost of the Current state is : " << current << endl << endl;
            PATH();
        }
        else{
            num = (float) rand()/ (float) (RAND_MAX) * 1;
            cout << "The NUM generated randomly : " << num << endl << endl;
            float var = (float)E/ (float)T;
            prob = exp(var);
            cout << "The value of E : " << E << endl;
            cout << "The value of T : " << T << endl;
            printf("The value of exp(E / T) : = %f\n", prob);


            if(num < prob){
                current = next;
                cout << "Randomly generated number is less than the probability, so the neighbor state is assigned as current state" << endl;
                cout << "Now cost of the Current state is : " << current << endl << endl;
                PATH();
            }
            else{
                cout << "Randomly generated number is greater than the probability, so current state value remains same." << endl;
                cout << "So cost of the Current state is : " << current << endl << endl;
            }
        }
    }
    cout << "----------------------------------------------------------------------------------------" << endl;
    finalSolution();

    return 0;
}

void cost(){
    srand(time(NULL));
    matrix[0][1] = rand() % 100 + 1;
    matrix[0][2] = rand() % 100 + 1;
    matrix[0][3] = rand() % 100 + 1;
    matrix[1][0] = rand() % 100 + 1;
    matrix[1][2] = rand() % 100 + 1;
    matrix[1][3] = rand() % 100 + 1;
    matrix[2][0] = rand() % 100 + 1;
    matrix[2][1] = rand() % 100 + 1;
    matrix[2][3] = rand() % 100 + 1;
    matrix[3][0] = rand() % 100 + 1;
    matrix[3][1] = rand() % 100 + 1;
    matrix[3][2] = rand() % 100 + 1;
}

void solution(){
    for(int i=0; i<SIZE; i++){
            if(i>0 && i<SIZE){
                cout << "->";
            }

            cout << arr[i];
        }
        putchar('\n');
}

void state(){
    int num2, num3, num1, NUM;
    bool check[SIZE] = {false};

    NUM = rand() % 4;

    arr[0] = NUM;
    arr[4] = NUM;
    check[NUM] = true;

    for(;;){
        num1 = rand() % 4;

        if(check[num1] == false){
            check[num1] = true;

            num2 = rand() % 4;
            if(check[num2] == false){
                check[num2] = true;

                num3 = rand() % 4;
                if(check[num3] == false){
                    arr[1] = num1;
                    arr[2] = num2;
                    arr[3] = num3;
                    break;
                }
                check[num2] = false;
            }
            check[num1] = false;
        }
    }
}

void PATH(){
    finalPath.clear();

    for(int i = 0; i < SIZE; i++)
        finalPath.push_back(arr[i]);
}

void finalSolution(){
    cout << endl;
    cout << "\t\t------------------" << endl;
    cout << "\t\t| Final solution |" << endl;
    cout << "\t\t------------------" << endl<<endl;

    cout << "Path : ";
    for(int i=0; i<finalPath.size(); i++){
            if(i>0 && i<finalPath.size()){
                cout << "->";
            }

            cout << finalPath[i];
        }
    putchar('\n');

    cout << "Cost of the path : " << current << endl;

}

void begiN(){
    cout << "\t\t\t---------------------------------\n";
    cout << "\t\t\t| TSP USING SIMULATED ANNEALING |\n";
    cout << "\t\t\t---------------------------------\n\n";

    cout << "\tImplemented By : \n";
    cout << "\t----------------\n";

    cout << "\tMD. GOLAM RASUL\t\tSHAMSE TASNIM CYNTHIA\n\n";
    cout << "\t2016-1-60-080\t\t2016-1-60-113\n\n";
    cout << "\tDepartment of Computer Science and Engineering, East West University\n\n";

    system("pause");
    system("CLS");



}
