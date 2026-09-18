/*
 * A ideia veio a partir da observação do output do helper.py
 * Verifiquei que a, a partir do 0, todo X = 0 + K * (5 ** a), onde a pertence aos inteiros e 5 ** a <= N, significava que X poderia ser decomposto em 5**a * B, onde B é um número inteiro.
 * Como a contagem de 0's finais depende da quantidade de parcelas de 10* e 10 pode ser decomposto em 2 * 5, precisamos apenas encontrar a quantidade de 2's* e 5'*s.
 * A multiplicação é cmutativa logo decompor X! é igual a decompor todas as suas parcelas (X * (X - 1) * (X - 2) ... * 1)
 * A parcela de 2's* é sempre maior do que a parcela de 5's* pois #nº pares até X > #nº de múltiplos de 5 até X para todo X
 * Como a relação de 2's e 5's deve ser de 1:1, então basta encontrarmos o min(2's, 5's). Como a propriedade acima se verifica, basta encontrarmos o número de parcelas de 5's
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;

    long long aux = 5;

    long long count = 0;
    
    while (aux <= N) {
        count += N / aux;  
        
        aux *= 5;
    }

    cout << count << "\n";
    
    return 0;
}

