#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>

using namespace std;

#define NLIN 9
#define NCOL 8

int Matriz_Num[NLIN][NCOL];
char Matriz_Char[NLIN][NCOL + 1];
int Indice_Coluna[NCOL];
int quant, enter;
char jogador;
string jogador1, jogador2, jogador3, jogador4, identificador1, identificador2, identificador3, identificador4;
int num_jogadores, cont = 0, quilates_jogador1 = 0, quilates_jogador2 = 0, quilates_jogador3 = 0, quilates_jogador4 = 0;

int i, j;

void matriz_numerica()
{
    unsigned seed = time(0);
    srand(seed);

    for (i = 0; i < NLIN; i++)
    {
        for (j = 0; j < NCOL; j++)
        {
            Matriz_Num[i][j] = (1 + rand() % 10);
        }
    }

    for (int k = 0; k < 16; k++) // 25% Pistas
    {
        Matriz_Num[(rand() % NLIN)][(rand() % NCOL)] = 44;
    }

    for (int k = 0; k < 10; k++) // 15% Armadilhas
    {
        Matriz_Num[(rand() % NLIN)][(rand() % NCOL)] = 10 + (1 + rand() % 10);
    }

    for (int k = 0; k < 10; k++) // 15% Diamantes
    {
        Matriz_Num[(rand() % NLIN)][(rand() % NCOL)] = 20 + (1 + rand() % 10);
    }

    for (i = 0; i < NLIN; i++)
    {
        for (j = 0; j < NCOL; j++)
        {
            cout << Matriz_Num[i][j] << "\t";
        }
        cout << endl
             << endl;
    }
}

void matriz_char()
{
    for (int i = 0; i < NLIN; i++)
    {
        Matriz_Char[i][NCOL] = '0' + i; // Preencha a última coluna com números
    }

    for (i = 0; i < NLIN; i++)
    {
        for (j = 0; j < NCOL; j++)
        {
            Matriz_Char[i][j] = 177;
        }
    }
}

void setColor(int color)
{
    std::cout << "\033[" << color << "m";
}

void Imprimir_Matriz()
{
    for (i = 0; i < NCOL; i++) // Indice coluna
    {
        cout << i << "\t";
    }
    cout << endl
         << endl;

    for (i = 0; i < NLIN; i++)
    {
        for (j = 0; j < NCOL + 1; j++)
        {
            cout << Matriz_Char[i][j] << "\t";
        }
        cout << endl
             << endl;
    }
}

bool ehConsoante(char c)
{
    c = tolower(c); // Converte para minúscula para verificar identificador1 independentemente do caso
    return (c >= 'b' && c <= 'z' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

void Ranking()
{
    switch (num_jogadores)
    {
    case 2:
        if (quilates_jogador1 > quilates_jogador2)
        {
            cout << "\t   #RANKING#  \t" << endl
                 << identificador1 << "\t\t=\t\t" << quilates_jogador1
                 << endl
                 << identificador2 << "\t\t=\t\t" << quilates_jogador2 << endl;
        }
        else
        {
            cout << "\t   #RANKING#  \t" << endl
                 << identificador2 << "\t\t=\t\t" << quilates_jogador2
                 << endl
                 << identificador1 << "\t\t=\t\t" << quilates_jogador1 << endl;
        }
        break;
    case 3:
        if (quilates_jogador1 > quilates_jogador2 && quilates_jogador1 > quilates_jogador3)
        {
            if (quilates_jogador2 > quilates_jogador3)
            {
                cout << "\t   #RANKING#  \t" << endl
                     << identificador1 << "\t\t=\t\t" << quilates_jogador1
                     << endl
                     << identificador2 << "\t\t=\t\t" << quilates_jogador2
                     << endl
                     << identificador3 << "\t\t=\t\t" << quilates_jogador3 << endl;
            }
            else
            {
                cout << "\t   #RANKING#  \t" << endl
                     << identificador1 << "\t\t=\t\t" << quilates_jogador1
                     << endl
                     << identificador3 << "\t\t=\t\t" << quilates_jogador3
                     << endl
                     << identificador2 << "\t\t=\t\t" << quilates_jogador2 << endl;
            }
        }
        else if (quilates_jogador2 > quilates_jogador1 && quilates_jogador2 > quilates_jogador3)
        {
            if (quilates_jogador1 > quilates_jogador3)
            {
                cout << "\t   #RANKING#  \t" << endl
                     << identificador2 << "\t\t=\t\t" << quilates_jogador2
                     << endl
                     << identificador1 << "\t\t=\t\t" << quilates_jogador1
                     << endl
                     << identificador3 << "\t\t=\t\t" << quilates_jogador3 << endl;
            }
            else
            {
                cout << "\t   #RANKING#  \t" << endl
                     << identificador2 << "\t\t=\t\t" << quilates_jogador2
                     << endl
                     << identificador3 << "\t\t=\t\t" << quilates_jogador3
                     << endl
                     << identificador1 << "\t\t=\t\t" << quilates_jogador1 << endl;
            }
        }
        else
        {
            if (quilates_jogador1 > quilates_jogador2)
            {
                cout << "\t   #RANKING#  \t" << endl
                     << identificador3 << "\t\t=\t\t" << quilates_jogador3
                     << endl
                     << identificador1 << "\t\t=\t\t" << quilates_jogador1
                     << endl
                     << identificador2 << "\t\t=\t\t" << quilates_jogador2 << endl;
            }
            else
            {
                cout << "\t   #RANKING#  \t" << endl
                     << identificador3 << "\t\t=\t\t" << quilates_jogador3
                     << endl
                     << identificador2 << "\t\t=\t\t" << quilates_jogador2
                     << endl
                     << identificador1 << "\t\t=\t\t" << quilates_jogador1 << endl;
            }
        }
        break;
    case 4:
        // Para 4 jogadores, é mais fácil usar um vetor e ordenar
        int quilates[] = {quilates_jogador1, quilates_jogador2, quilates_jogador3, quilates_jogador4};
        string identificadores[] = {identificador1, identificador2, identificador3, identificador4};
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (quilates[i] < quilates[j])
                {
                    int temp = quilates[i];
                    quilates[i] = quilates[j];
                    quilates[j] = temp;
                    string tempIdentificador = identificadores[i];
                    identificadores[i] = identificadores[j];
                    identificadores[j] = tempIdentificador;
                }
            }
        }
        cout << "\t   #RANKING#  \t" << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << identificadores[i] << "\t\t=\t\t" << quilates[i] << endl;
        }
        break;
    }
    cout << endl
         << endl;
}

void Comandos_Iniciais()
{
    cout << "Digite o numero de jogadores: ";
    cin >> num_jogadores;
    cin.ignore(); // Limpa o buffer do teclado

    if (num_jogadores >= 2)
    {
        cout << "Insira o nome do jogador 1: ";
        getline(cin, jogador1);
        int count = 0;
        for (char c : jogador1)
        {
            if (ehConsoante(c))
            {
                identificador1 += c;
                count++;
                if (count == 2)
                    break;
            }
        }
        cout << identificador1 << endl;
        cout << "Insira o nome do jogador 2: ";
        getline(cin, jogador2);
        count = 0;
        for (char c : jogador2)
        {
            if (ehConsoante(c))
            {
                identificador2 += c;
                count++;
                if (count == 2)
                    break;
            }
        }
        cout << identificador2 << endl;
    }

    if (num_jogadores >= 3)
    {
        cout << "Insira o nome do jogador 3: ";
        getline(cin, jogador3);
        int count = 0;
        for (char c : jogador3)
        {
            if (ehConsoante(c))
            {
                identificador3 += c;
                count++;
                if (count == 2)
                    break;
            }
            cout << identificador3 << endl;
        }

        if (num_jogadores == 4)
        {
            cout << "Insira o nome do jogador 4: ";
            getline(cin, jogador4);
            int count = 0;
            for (char c : jogador4)
            {
                if (ehConsoante(c))
                {
                    identificador4 += c;
                    count++;
                    if (count == 2)
                        break;
                }
            }
            cout << identificador4 << endl;
        }
    }
}

void Comandos()
{
    int jogador_atual = 1; // Começa no jogador 1
    while (cont < NLIN * NCOL)
    { // Continua até que todos os elementos sejam preenchidos
        if (jogador_atual == 1)
        {
            system("clear||cls");
            setColor(36);
            Ranking();
            Imprimir_Matriz();
            cout << identificador1 << " digite a coluna e a linha escolhida: " << endl;
            cin >> j >> i;
            if ((Matriz_Num[i][j]) <= 10)
            {

                Matriz_Char[i][j] = 92;
                Imprimir_Matriz();
                cout << "NADA" << endl;
            }

            if ((Matriz_Num[i][j] == 44))
            {
                Matriz_Char[i][j] = 64;
                 Imprimir_Matriz();
                bool pistaEncontrada = false;
                for (int p = 0; p < NLIN && !pistaEncontrada; p++)
                {
                    for (int t = 0; t < NCOL && !pistaEncontrada; t++)
                    {
                        if ((Matriz_Num[p][t] > 20) && (Matriz_Num[p][t] < 44))
                        {
                            cout << "Pista: Diamante na linha :" << p << endl;
                            pistaEncontrada = true;
                        }
                    }
                }
               
            }

            if (((Matriz_Num[i][j]) > 10) && ((Matriz_Num[i][j]) <= 20))
            {
                if ((Matriz_Num[i][j] % 10) == 0 || (Matriz_Num[i][j] % 10) == 1)
                {
                    Matriz_Char[i][j] = 79;
                     Imprimir_Matriz();
                    cout << "Tunel sem saida ao sair do tunel, o jogador perde 10 de seus quilates." << endl;
                    quilates_jogador1 = quilates_jogador1 - 10;
                
                }
                if ((Matriz_Num[i][j] % 10) == 3 || (Matriz_Num[i][j] % 10) == 4)
                {
                    Matriz_Char[i][j] = 45;
                     Imprimir_Matriz();
                    cout << "Esconderijo secreto: o jogador fica invisível e desconta 5 quilates do(s)oponente(s);." << endl;
                    quilates_jogador2 = quilates_jogador2 - 5;
                    quilates_jogador3 = quilates_jogador3 - 5;
                    quilates_jogador4 = quilates_jogador4 - 5;
                   
                }

                if ((Matriz_Num[i][j] % 10) == 5 || (Matriz_Num[i][j] % 10) == 6 || (Matriz_Num[i][j] % 10) == 7 || (Matriz_Num[i][j] % 10) == 8)
                {
                    Matriz_Char[i][j] = 43;
                     Imprimir_Matriz();
                    cout << "Prossiga: como o jogador está no caminho certo, seus quilates sao acrescidos em 3 pontos." << endl;
                    quilates_jogador1 = quilates_jogador1 + 3;
                   
                }

                if ((Matriz_Num[i][j] % 10) == 9 || (Matriz_Num[i][j] % 10) == 2)
                {
                    Matriz_Char[i][j] = 38;
                     Imprimir_Matriz();
                    cout << "Mina Dourada!: seus quilates sao duplicados." << endl;
                    quilates_jogador1 = quilates_jogador1 * 2;
                   
                }
            }

            if ((Matriz_Num[i][j]) > 20 && (Matriz_Num[i][j]) < 44)
            {
                int diamante = (Matriz_Num[i][j]) % 10;
                Matriz_Char[i][j] = 36;
                Matriz_Num[i][j] = 88;
                 Imprimir_Matriz();
                cout << "Diamante!!! +" << diamante + 1 << " quilates." << endl;
                quilates_jogador1 = quilates_jogador1 + diamante + 1;
               
            }
            system("pause");
        }
        else if (jogador_atual == 2)
        {
            system("clear||cls");
            setColor(32);
            Ranking();
            Imprimir_Matriz();
            cout << identificador2 << " digite a coluna e a linha escolhida: " << endl;
            cin >> j >> i;
            if ((Matriz_Num[i][j]) <= 10)
            {

                Matriz_Char[i][j] = 92;
                Imprimir_Matriz();
                cout << "NADA" << endl;
            }

            if ((Matriz_Num[i][j] == 44))
            {
                Matriz_Char[i][j] = 64;
                Imprimir_Matriz();
                bool pistaEncontrada = false;
                for (int p = 0; p < NLIN && !pistaEncontrada; p++)
                {
                    for (int t = 0; t < NCOL && !pistaEncontrada; t++)
                    {
                        if ((Matriz_Num[p][t] > 20) && (Matriz_Num[p][t] < 44))
                        {
                            cout << "Pista: Diamante na linha :" << p << endl;
                            pistaEncontrada = true;
                        }
                    }
                }
            }

            if (((Matriz_Num[i][j]) > 10) && ((Matriz_Num[i][j]) <= 20))
            {
                if ((Matriz_Num[i][j] % 10) == 0 || (Matriz_Num[i][j] % 10) == 1)
                {
                    Matriz_Char[i][j] = 79;
                    Imprimir_Matriz();
                    cout << "Tunel sem saida ao sair do tunel, o jogador perde 10 de seus quilates." << endl;
                    quilates_jogador2 = quilates_jogador2 - 10;
                }
                if ((Matriz_Num[i][j] % 10) == 3 || (Matriz_Num[i][j] % 10) == 4)
                {
                    Matriz_Char[i][j] = 45;
                    Imprimir_Matriz();
                    cout << "Esconderijo secreto: o jogador fica invisível e desconta 5 quilates do(s)oponente(s);." << endl;
                    quilates_jogador1 = quilates_jogador1 - 5;
                    quilates_jogador3 = quilates_jogador3 - 5;
                    quilates_jogador4 = quilates_jogador4 - 5;
                }

                if ((Matriz_Num[i][j] % 10) == 5 || (Matriz_Num[i][j] % 10) == 6 || (Matriz_Num[i][j] % 10) == 7 || (Matriz_Num[i][j] % 10) == 8)
                {
                    Matriz_Char[i][j] = 43;
                    Imprimir_Matriz();
                    cout << "Prossiga: como o jogador está no caminho certo, seus quilates sao acrescidos em 3 pontos." << endl;
                    quilates_jogador2 = quilates_jogador2 + 3;
                }

                if ((Matriz_Num[i][j] % 10) == 9 || (Matriz_Num[i][j] % 10) == 2)
                {
                    Matriz_Char[i][j] = 38;
                    Imprimir_Matriz();
                    cout << "Mina Dourada!: seus quilates sao duplicados." << endl;
                    quilates_jogador2 = quilates_jogador2 * 2;
                }
            }

            if ((Matriz_Num[i][j]) > 20 && (Matriz_Num[i][j]) < 44)
            {
                int diamante = (Matriz_Num[i][j]) % 10;
                Matriz_Char[i][j] = 36;
                Matriz_Num[i][j] = 88;
                Imprimir_Matriz();
                cout << "Diamante!!! +" << diamante + 1 << " quilates." << endl;
                quilates_jogador2 = quilates_jogador2 + diamante + 1;
            }
            system("pause");
        }
        else if (jogador_atual == 3)
        {
            system("clear||cls");
            setColor(33);
            Ranking();
            Imprimir_Matriz();
            cout << identificador3 << " digite a coluna e a linha escolhida: " << endl;
            cin >> j >> i;
            if ((Matriz_Num[i][j]) <= 10)
            {
                Matriz_Char[i][j] = 92;
                Imprimir_Matriz();
                cout << "NADA" << endl;
            }

            if ((Matriz_Num[i][j] == 44))
            {
                Matriz_Char[i][j] = 64;
                Imprimir_Matriz();
                bool pistaEncontrada = false;
                for (int p = 0; p < NLIN && !pistaEncontrada; p++)
                {
                    for (int t = 0; t < NCOL && !pistaEncontrada; t++)
                    {
                        if ((Matriz_Num[p][t] > 20) && (Matriz_Num[p][t] < 44))
                        {
                            cout << "Pista: Diamante na linha :" << p << endl;
                            pistaEncontrada = true;
                        }
                    }
                }
            }

            if (((Matriz_Num[i][j]) > 10) && ((Matriz_Num[i][j]) <= 20))
            {
                if ((Matriz_Num[i][j] % 10) == 0 || (Matriz_Num[i][j] % 10) == 1)
                {
                    Matriz_Char[i][j] = 79;
                    Imprimir_Matriz();
                    cout << "Tunel sem saida ao sair do tunel, o jogador perde 10 de seus quilates." << endl;
                    quilates_jogador3 = quilates_jogador3 - 10;
                }
                if ((Matriz_Num[i][j] % 10) == 3 || (Matriz_Num[i][j] % 10) == 4)
                {
                    Matriz_Char[i][j] = 45;
                    Imprimir_Matriz();
                    cout << "Esconderijo secreto: o jogador fica invisível e desconta 5 quilates do(s)oponente(s);." << endl;
                    quilates_jogador2 = quilates_jogador2 - 5;
                    quilates_jogador1 = quilates_jogador1 - 5;
                    quilates_jogador4 = quilates_jogador4 - 5;
                }

                if ((Matriz_Num[i][j] % 10) == 5 || (Matriz_Num[i][j] % 10) == 6 || (Matriz_Num[i][j] % 10) == 7 || (Matriz_Num[i][j] % 10) == 8)
                {
                    Matriz_Char[i][j] = 43;
                    Imprimir_Matriz();
                    cout << "Prossiga: como o jogador está no caminho certo, seus quilates sao acrescidos em 3 pontos." << endl;
                    quilates_jogador3 = quilates_jogador3 + 3;
                }

                if ((Matriz_Num[i][j] % 10) == 9 || (Matriz_Num[i][j] % 10) == 2)
                {
                    Matriz_Char[i][j] = 38;
                    Imprimir_Matriz();
                    cout << "Mina Dourada!: seus quilates sao duplicados." << endl;
                    quilates_jogador3 = quilates_jogador3 * 2;
                }
            }

            if ((Matriz_Num[i][j]) > 20 && (Matriz_Num[i][j]) < 44)
            {
                int diamante = (Matriz_Num[i][j]) % 10;
                Matriz_Char[i][j] = 36;
                Matriz_Num[i][j] = 88;
                Imprimir_Matriz();
                cout << "Diamante!!! +" << diamante + 1 << " quilates." << endl;
                quilates_jogador3 = quilates_jogador3 + diamante + 1;
            }
            system("pause");
        }
        else if (jogador_atual == 4)
        {
            system("clear||cls");
            setColor(35);
            Ranking();
            Imprimir_Matriz();
            cout << identificador4 << " digite a coluna e a linha escolhida: " << endl;
            cin >> j >> i;
            if ((Matriz_Num[i][j]) <= 10)
            { 
                Matriz_Char[i][j] = 92;
                Imprimir_Matriz();
                cout << "NADA" << endl;
            }

            if ((Matriz_Num[i][j] == 44))
            {
                Matriz_Char[i][j] = 64;
                Imprimir_Matriz();
                bool pistaEncontrada = false;
                for (int p = 0; p < NLIN && !pistaEncontrada; p++)
                {
                    for (int t = 0; t < NCOL && !pistaEncontrada; t++)
                    {
                        if ((Matriz_Num[p][t] > 20) && (Matriz_Num[p][t] < 44))
                        {
                            cout << "Pista: Diamante na linha :" << p << endl;
                            pistaEncontrada = true;
                        }
                    }
                }
            }

            if (((Matriz_Num[i][j]) > 10) && ((Matriz_Num[i][j]) <= 20))
            {
                if ((Matriz_Num[i][j] % 10) == 0 || (Matriz_Num[i][j] % 10) == 1)
                {
                    Matriz_Char[i][j] = 79;
                    Imprimir_Matriz();
                    cout << "Tunel sem saida ao sair do tunel, o jogador perde 10 de seus quilates." << endl;
                    quilates_jogador4 = quilates_jogador4 - 10;
                }
                if ((Matriz_Num[i][j] % 10) == 3 || (Matriz_Num[i][j] % 10) == 4)
                {
                    Matriz_Char[i][j] = 45;
                    Imprimir_Matriz();
                    cout << "Esconderijo secreto: o jogador fica invisível e desconta 5 quilates do(s)oponente(s);." << endl;
                    quilates_jogador2 = quilates_jogador2 - 5;
                    quilates_jogador3 = quilates_jogador3 - 5;
                    quilates_jogador1 = quilates_jogador1 - 5;
                }

                if ((Matriz_Num[i][j] % 10) == 5 || (Matriz_Num[i][j] % 10) == 6 || (Matriz_Num[i][j] % 10) == 7 || (Matriz_Num[i][j] % 10) == 8)
                {
                    Matriz_Char[i][j] = 43;
                    Imprimir_Matriz();
                    cout << "Prossiga: como o jogador está no caminho certo, seus quilates sao acrescidos em 3 pontos." << endl;
                    quilates_jogador4 = quilates_jogador4 + 3;
                }

                if ((Matriz_Num[i][j] % 10) == 9 || (Matriz_Num[i][j] % 10) == 2)
                {
                    Matriz_Char[i][j] = 38;
                    Imprimir_Matriz();
                    cout << "Mina Dourada!: seus quilates sao duplicados." << endl;
                    quilates_jogador4 = quilates_jogador4 * 2;
                }
            }

            if ((Matriz_Num[i][j]) > 20 && (Matriz_Num[i][j]) < 44)
            {
                int diamante = (Matriz_Num[i][j]) % 10;
                Matriz_Char[i][j] = 36;
                Matriz_Num[i][j] = 88;
                Imprimir_Matriz();
                cout << "Diamante!!! +" << diamante + 1 << " quilates." << endl;
                quilates_jogador4 = quilates_jogador4 + diamante + 1;
            }
            system("pause");
        }
        jogador_atual = (jogador_atual % num_jogadores) + 1; // Proximo jogador
        cont++;
    }
    system("clear||cls");
    setColor(35);
    cout<<"\t\tRANKING FINAL\t\t"<<endl<<endl;
    Ranking();
}

int main()
{
    Comandos_Iniciais();
    matriz_numerica();

    cout << endl
         << endl;
    matriz_char();
    Comandos();
}