# include<algorithm>
# include<iostream>
# include<cmath>
# include<vector>

using namespace std;

struct Interval{
    double right, left;
};

bool compare(Interval a, Interval b){
    if(a.left != b.left){
        return a.left < b.left;
    }
    else{
        return a.right < b.right;
    }
}

int main(void){
    int n, l, w;

    while(cin>>n>>l>>w){
        vector<Interval> interval;
        for(int i=0; i<n; i++){
            double center, radius;
            cin>>center>>radius;

            if(2*radius >= w){
                double len = sqrt((double)radius*radius - (double)w*w / 4.0);
                Interval a;
                a.left = max(0.0, center-len);
                a.right = min((double)l, center+len);
                interval.push_back(a);
            }
        }

        sort(interval.begin(), interval.end(), compare);

        int ans = 0, old_idx = 0;
        double end=0, reach=0;
        while(reach<l){
            int farthest_idx = old_idx;
            double new_end = end;
            for(int i=farthest_idx; i<interval.size(); i++){
                if(interval[i].left>end){
                    break;
                }
                if(interval[i].right>=new_end){
                    new_end=interval[i].right;
                    farthest_idx = i+1;
                }
            }
            
            if(farthest_idx==old_idx){
                break;
            }
            else{
                old_idx = farthest_idx;
            }
            ans++;
            reach = end = new_end;
        }

        if(end<l){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }

    return 0;
}