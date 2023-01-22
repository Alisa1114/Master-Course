#include<iostream>
#include<vector>
#include<iomanip>
#include<time.h>

using namespace std;

vector<double> probs;

double compute_total_prob(int start, int end, int k){
    double total_prob=0.0;

    // cout<<start<<" "<<end<<" ";

    if((end-start+1)>k){

        for(int i=start; i<start+k && i<=end; i++){
            double prob=1.0-probs[i];
            
            // cout<<i<<" ";

            for(int j=start; j<=i-1; j++){
                prob *= probs[j];
            }
            // cout<<prob<<" ";
            prob *= compute_total_prob(i+1, end, k);
            // cout<<prob<<" ";
            
            total_prob += prob;

            // cout<<total_prob<<endl;
        }
        return total_prob;
    }
    else if((end-start+1)==k) {
        double prob=1.0;
        for(int j=start; j<=end; j++){
            prob*=probs[j];
        }
        return 1.0 - prob;
    } 
    else if((end-start+1)<k){
        return 1.0;
    }

    return total_prob;
}

int main()
{
    int n, k;
    double start, end;
    
    while(cin>>n){
        if (n==0)
            break;

        cin>>k;

        for(int i=0; i<n; i++){
            double p;
            cin>>p;
            probs.push_back(p);
        }

        // start = clock();
        double total_prob = compute_total_prob(0, n-1, k) ;

        cout<<fixed<<setprecision(5)<<total_prob<<endl;

        // end = clock();
        // cout<< "Spend "<<(end-start)/CLOCKS_PER_SEC<<" sec"<<endl;

        probs.clear();
    }
    
    return 0;
}