#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int numParticipantes;
    int numJogos;

    cout << "Bem-vindo ao Sistema de Bolao v2.0!" << endl;
    cout << "Quantos participantes o bolao tera? ";
    cin >> numParticipantes;

    // Vetores dinâmicos para armazenar nomes e pontos (convertendo o int para size_t)
    vector<string> nomes(static_cast<size_t>(numParticipantes));
    vector<int> pontos(static_cast<size_t>(numParticipantes), 0);

    for (size_t i = 0; i < nomes.size(); i++) {
        cout << "Nome do Participante " << i + 1 << ": ";
        cin >> nomes[i];
    }
    
    cout << "\nQuantos jogos o bolao tera? ";
    cin >> numJogos;

    // Loop que processa os jogos e as apostas
    for (int i = 1; i <= numJogos; i++) {
        string timeA, timeB;
        int realA, realB;

        cout << "\n--- Jogo " << i << " ---" << endl;
        
        // Registrar jogo e placar real
        cout << "Nome do Time A: ";
        cin >> timeA;
        cout << "Nome do Time B: ";
        cin >> timeB;

        cout << "\nQual foi o placar REAL do jogo?" << endl;
        cout << "Gols do " << timeA << ": ";
        cin >> realA;
        cout << "Gols do " << timeB << ": ";
        cin >> realB;

        // Processar os palpites de cada participante
        for (size_t p = 0; p < nomes.size(); p++) {
            int betA, betB;
            cout << "\n> Palpite de " << nomes[p] << ":" << endl;
            cout << "Gols " << timeA << ": ";
            cin >> betA;
            cout << "Gols " << timeB << ": ";
            cin >> betB;

            // Cálculo dos pontos
            if (betA == realA && betB == realB) {
                pontos[p] += 10;
            } else if (realA > realB && betA > betB) {
                pontos[p] += 5;
            } else if (realA < realB && betA < betB) {
                pontos[p] += 5;
            } else if (realA == realB && betA == betB) {
                pontos[p] += 2;
            }
        }
    }

    // Exibir Ranking Final
    // Ordenando os vetores de forma decrescente com base nos pontos
    for (size_t i = 0; i + 1 < nomes.size(); i++) {
        for (size_t j = 0; j + i + 1 < nomes.size(); j++) {
            if (pontos[j] < pontos[j + 1]) {
                swap(pontos[j], pontos[j + 1]);
                swap(nomes[j], nomes[j + 1]);
            }
        }
    }

    cout << "\n===============================" << endl;
    cout << "===      RANKING FINAL      ===" << endl;
    cout << "===============================" << endl;
    for (size_t i = 0; i < nomes.size(); i++) {
        cout << i + 1 << "o Lugar: " << nomes[i] << " com " << pontos[i] << " pontos" << endl;
    }
    cout << "===============================" << endl;

    return 0;
}
