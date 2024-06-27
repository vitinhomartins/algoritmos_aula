#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;


string names[4] { "Vitinho", "Anny", "Dante", "Manu"};

typedef struct {
    float vida;
    float defesa;
    float ataque;
    string name;
} jogador;

jogador p[4];

float inversenow (float a) {

    if(a < 0) {
        a = a * -1;
    }    
    return a;
}

void declaration (int a, int b) {
    srand(time(nullptr));
    float differenteattack=0;
    p[a].name = names[a];
    p[b].name = names[b];
    p[a].ataque = rand() % 140;
    p[b].ataque = rand() % 140;
    differenteattack = inversenow(p[a].ataque - p[b].ataque);
    inversenow(differenteattack);
    cout << differenteattack << endl;
    while(differenteattack > 20) {
        p[a].ataque = rand() % 140;
        p[b].ataque = rand() % 140;
        differenteattack = p[a].ataque - p[b].ataque;
        inversenow(differenteattack);        
    }
    p[a].defesa = inversenow(rand() % 140);
    p[b].defesa = inversenow(rand() % 140);
    differenteattack = p[a].defesa - p[b].defesa;
    inversenow(differenteattack);
    while(differenteattack > 20) {
        p[a].defesa = inversenow(rand() % 140);
        p[b].defesa = inversenow(rand() % 140);
        differenteattack = p[a].defesa - p[b].defesa;
        inversenow(differenteattack);        
    } 
    p[a].vida = 100.00;
    p[b].vida = 100.0;
}

void overgame (int number, int number2) {
    p[number].name = "";
    p[number].ataque = 0;
    p[number].defesa = 0;
    p[number].vida = 0;
    p[number2].name = "";
    p[number2].ataque = 0;
    p[number2].defesa = 0;
    p[number2].vida = 0;
}

int main()
{
    srand(time(nullptr));
    int number = rand()%4;
    int number2 = rand()%4; 
    while(number == number2) {
        number2 = rand()%4;  
    }
    declaration(number, number2);
    cout << p[number].name << " " <<  p[number2].name << endl;        
    cout << p[number].ataque << " " <<  p[number2].ataque << endl; 
    cout << p[number].defesa << " " <<  p[number2].defesa << endl; 
    cout << p[number].vida << " " <<  p[number2].vida << endl; 
    return 0;
}