#include <iostream>
#include <string>

using namespace std;

int main() {
    string nome1, nome2, nome3;
    int pontos1 = 0, pontos2 = 0, pontos3 = 0;
    int numJogos;

    cout << "Bem-vindo ao Sistema de Bolao!" << endl;
    cout << "Nome do Participante 1: ";
    cin >> nome1;
    cout << "Nome do Participante 2: ";
    cin >> nome2;
    cout << "Nome do Participante 3: ";
    cin >> nome3;
    
    cout << "\nQuantos jogos o bolao tera? ";
    cin >> numJogos;

    // Um unico loop que processa o jogo real e as apostas dos tres participantes
    for (int i = 1; i <= numJogos; i++) {
        string timeA, timeB;
        int realA, realB;

        cout << "\n--- Jogo " << i << " ---" << endl;
        
        // 1 - Registrar jogo e placar real
        cout << "Nome do Time A: ";
        cin >> timeA;
        cout << "Nome do Time B: ";
        cin >> timeB;

        cout << "\nQual foi o placar REAL do jogo?" << endl;
        cout << "Gols do " << timeA << ": ";
        cin >> realA;
        cout << "Gols do " << timeB << ": ";
        cin >> realB;

        // --- Aposta e Calculo do Participante 1 ---
        int betA1, betB1;
        cout << "\n> Palpite de " << nome1 << ":" << endl;
        cout << "Gols " << timeA << ": ";
        cin >> betA1;
        cout << "Gols " << timeB << ": ";
        cin >> betB1;

        if (betA1 == realA && betB1 == realB) {
            pontos1 += 10;
        } else if (realA > realB && betA1 > betB1) {
            pontos1 += 5;
        } else if (realA < realB && betA1 < betB1) {
            pontos1 += 5;
        } else if (realA == realB && betA1 == betB1) {
            pontos1 += 2;
        }

        // --- Aposta e Calculo do Participante 2 ---
        int betA2, betB2;
        cout << "\n> Palpite de " << nome2 << ":" << endl;
        cout << "Gols " << timeA << ": ";
        cin >> betA2;
        cout << "Gols " << timeB << ": ";
        cin >> betB2;

        if (betA2 == realA && betB2 == realB) {
            pontos2 += 10;
        } else if (realA > realB && betA2 > betB2) {
            pontos2 += 5;
        } else if (realA < realB && betA2 < betB2) {
            pontos2 += 5;
        } else if (realA == realB && betA2 == betB2) {
            pontos2 += 2;
        }

        // --- Aposta e Calculo do Participante 3 ---
        int betA3, betB3;
        cout << "\n> Palpite de " << nome3 << ":" << endl;
        cout << "Gols " << timeA << ": ";
        cin >> betA3;
        cout << "Gols " << timeB << ": ";
        cin >> betB3;

        if (betA3 == realA && betB3 == realB) {
            pontos3 += 10;
        } else if (realA > realB && betA3 > betB3) {
            pontos3 += 5;
        } else if (realA < realB && betA3 < betB3) {
            pontos3 += 5;
        } else if (realA == realB && betA3 == betB3) {
            pontos3 += 2;
        }
    }

    // 4 - Exibir Ranking Final
    // Para ordenar sem usar arrays, podemos fazer trocas manuais de variaveis
    // Se o ponto do proximo for maior, trocamos as variaveis de posicao para ordenar decrescente
    
    if (pontos1 < pontos2) {
        int tempP = pontos1; pontos1 = pontos2; pontos2 = tempP;
        string tempN = nome1; nome1 = nome2; nome2 = tempN;
    }
    if (pontos1 < pontos3) {
        int tempP = pontos1; pontos1 = pontos3; pontos3 = tempP;
        string tempN = nome1; nome1 = nome3; nome3 = tempN;
    }
    if (pontos2 < pontos3) {
        int tempP = pontos2; pontos2 = pontos3; pontos3 = tempP;
        string tempN = nome2; nome2 = nome3; nome3 = tempN;
    }

    cout << "\n===============================" << endl;
    cout << "===      RANKING FINAL      ===" << endl;
    cout << "===============================" << endl;
    cout << "1o Lugar: " << nome1 << " com " << pontos1 << " pontos" << endl;
    cout << "2o Lugar: " << nome2 << " com " << pontos2 << " pontos" << endl;
    cout << "3o Lugar: " << nome3 << " com " << pontos3 << " pontos" << endl;
    cout << "===============================" << endl;

    return 0;
}
