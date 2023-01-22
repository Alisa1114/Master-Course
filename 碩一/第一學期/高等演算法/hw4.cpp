# include <iostream>
# include<algorithm>
# include<climits>

// #include <bits/stdc++.h>

using namespace std;

int main(void){
    int m,n;

    while(cin>>m>>n){
        long long table[m][n], weight[m][n];
        int next[m][n-1];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>table[i][j];
            }
        }

        for(int j=n-1; j>=0; j--){
            for(int i=0; i<m; i++){
                if(j==n-1){
                    weight[i][j]=table[i][j];
                }
                else{
                    weight[i][j] = LLONG_MAX;

                    int nextRow[3] = {(i-1+m)%m, i, (i+1)%m};
                    sort(nextRow, nextRow+3);

                    for(int k=0; k<3; k++){
                        if(table[i][j]+weight[nextRow[k]][j+1]<weight[i][j]){
                            weight[i][j] = table[i][j]+weight[nextRow[k]][j+1];
                            next[i][j] = nextRow[k];
                        }
                    }
                }
            }
        }

        int first=0;
        for(int i=0; i<m; i++){
            if(weight[first][0]>weight[i][0]){
                first=i;
            }
        }

        cout<<first+1;
        for(int i=first, j=0; j<n-1; i=next[i][j], j++){
            cout<<" "<<next[i][j]+1;
        }
        cout<<endl;
        cout<<weight[first][0]<<endl;
    }

    return 0;
}