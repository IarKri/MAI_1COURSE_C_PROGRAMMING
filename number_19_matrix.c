#include <stdio.h>

int main(void) {

    //инициализация значений
    int maxn = 8;
    int n;
    int m[maxn * maxn];

    scanf("%d", &n);

    //линейное представление матрицы
    for (int k = 0; k < n * n; ++k)
        scanf("%d", &m[k]);

    //блок поиска максимального числа в строке матрицы и размещение на диагональную позицию
    for (int i = 0; i < n; ++i) {
        int max = m[i * n];

        for (int j = 1; j < n; ++j) {
            if (m[i * n + j] > max)
                max = m[i * n + j];
        }

        m[i * n + i] = max;
    }


    //обратный перевод линейного представления матрицы в классический вид и вывод результата
    for (int k = 0; k < n * n; ++k) {
        printf("%d ", m[k]);

        if (k % n == n - 1)
            putchar("\n");
    }

    return 0;
}