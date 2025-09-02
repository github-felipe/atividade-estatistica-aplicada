#include <iostream>
#include <windows.h>
#include <iomanip>
#include <math.h>

//0(ao menos um curto), 5(dois longos), 10(um longo), 15(componentes perfeitos)
using namespace std;
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    double cilindro_bom = 0.8;
    double cilindro_longo = 0.1;
    double cilindro_curto = 0.1;

    double esfera_bom = 0.7;
    double esfera_longo = 0.2;
    double esfera_curto = 0.1;

    double chance_zero, chance_cinco, chance_dez, chance_quinze, lucro_medio,varianca,  desvio_padrao, custo_medio;
    cout << fixed << setprecision(2);
    cout << "Tabela representando todas as combinacoes:" << endl;
    cout << "________________________________________" << endl;
    cout << "|Combinacao (cilindro, esfera)|P(X = x)|" << endl;
    cout << "________________________________________" << endl;
    cout << "|Bom, Bom                     |" << cilindro_bom * esfera_bom << "    |" << endl;
    cout << "|Bom, Longo                   |" << cilindro_bom * esfera_longo << "    |" << endl;
    cout << "|Bom, Curto                   |" << cilindro_bom * esfera_curto << "    |" << endl;
    cout << "|Longo, Bom                   |" << cilindro_longo * esfera_bom << "    |" << endl;
    cout << "|Longo, Longo                 |" << cilindro_longo * esfera_longo << "    |" << endl;
    cout << "|longo, Curto                 |" << cilindro_longo * esfera_curto << "    |" << endl;
    cout << "|Curto, Bom                   |" << cilindro_curto * esfera_bom << "    |" << endl;
    cout << "|Curto, Longo                 |" << cilindro_curto * esfera_longo << "    |" << endl;
    cout << "|Curto, Curto                 |" << cilindro_curto * esfera_curto << "    |" << endl;
    cout << "________________________________________\n" << endl;

    chance_zero = (cilindro_bom * esfera_curto) + (cilindro_longo * esfera_curto) + (cilindro_curto * esfera_bom) + (cilindro_curto * esfera_longo) + (cilindro_curto * esfera_curto);
    chance_cinco = cilindro_longo * esfera_longo;
    chance_dez = (cilindro_bom * esfera_longo) + (cilindro_longo * esfera_bom);
    chance_quinze = cilindro_bom * esfera_bom;

    cout << "Tabela de lucro por conjunto montado:" << endl;
    cout << "___________________" << endl;
    cout << "|Lucro   |P(X = x)|" << endl;
    cout << "___________________" << endl;
    cout << "|R$:15,00|" << chance_quinze << "    |" << endl;
    cout << "|R$:10,00|" << chance_dez << "    |" << endl;
    cout << "|R$: 5,00|" << chance_cinco << "    |" << endl;
    cout << "|R$: 0,00|" << chance_zero << "    |" << endl;
    cout << "___________________\n" << endl;

    lucro_medio = 15*chance_quinze + 10*chance_dez + 5*chance_cinco;
    varianca = pow((0-lucro_medio), 2)*chance_zero + pow((5-lucro_medio), 2)*chance_cinco + pow((10-lucro_medio), 2)*chance_dez + pow((15-lucro_medio), 2)*chance_quinze;
    desvio_padrao = sqrt(varianca);
    cout << "Lucro medio: R$" << lucro_medio << " | Varianca: " << varianca << " | Desvio padrao: R$:" << desvio_padrao << endl;

    cout << "\nCusto de recuperacao de cada conjunto produzido:" << endl;
    cout << "_______________________________" << endl;
    cout << "|Custo de recuperacao|P(Y = y)|" << endl;
    cout << "_______________________________" << endl;
    cout << "|R$: 0,00            |" << chance_quinze + chance_zero << "    |" << endl;
    cout << "|R$: 5,00            |" << chance_dez << "    |" << endl;
    cout << "|R$:10,00            |" << chance_cinco << "    |" << endl;
    cout << "_______________________________\n" << endl;

    custo_medio = 10*chance_cinco + 5*chance_dez;
    varianca = pow((0-custo_medio), 2)*(chance_quinze+chance_zero) + pow((5-custo_medio), 2)*chance_dez + pow((10-custo_medio), 2)*chance_cinco;
    desvio_padrao = sqrt(varianca);
    cout << "Custo medio de recuperacao: R$:" << custo_medio << " | Varianca: " << varianca << " | Desvio padrao: R$:" << desvio_padrao << endl;
    cout << endl;

    system("pause");
    return 0;
}
