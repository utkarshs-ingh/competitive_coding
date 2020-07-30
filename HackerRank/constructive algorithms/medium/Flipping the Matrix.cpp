#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,n) for(int i=a;i<(n);i++)

// Complete the flippingMatrix function below.
int flippingMatrix(vector<vector<int>> v, int n) {
    int sum = 0;
    FOR(i,0,n){
        FOR(j,0,n){
            int a = v[i][j];
            int b = v[i][2*n - j - 1];
            int c = v[2*n - i - 1][j];
            int d = v[2*n - i - 1][2*n - j - 1];
            sum += max({a,b,c,d});
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> matrix(2*n);
        for (int i = 0; i < 2*n; i++) {
            matrix[i].resize(2*n);

            for (int j = 0; j < 2*n; j++) {
                cin >> matrix[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = flippingMatrix(matrix,n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
