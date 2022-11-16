#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec vector<long long int>
#define pi pair<long long int,long long int>
#define MOD 1000000007
// cout<<"Case #"<<q<<": "<<answer<<"\n";
#define subMod ((a%M -b%M +MOD)%MOD
#define addMod (a%M + b%M)%MOD
#define mulMod ((a%M)*(b%M))%MOD
using namespace std;
int main(){
		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		int n = 5;
		int t = 0;
		int time_slice = 2;
		float avgwt = 0;
		float avgta = 0;
		int curr_t = 0;
		int curr_proc = 0;
		int pid[5] = {1,2,3,4,5};
		int at[5] = {0,0,6,11,12};
		int bt[5]   =  {4,3,7,4,2};
		int time_remain[5];
		int fi[5];
		int ct[5];
		int tat[5];
		int wt[5];

		for(int i=0;i<5;i++){
			fi[i] = 0;
		}
		for(int i=0;i<5;i++){
			time_remain[i] = bt[i];
		}
		int g = 0;
		while(true){
			int mini = INT_MAX;
			// if(g==5){
			// 	break;
			// }
			// g++;
			if(t==n){
				break;
			}
			for(int i=0;i<n;i++){
				if(fi[i]==0 && curr_t>=at[i] && bt[i]<mini){
					mini = bt[i];
					curr_proc = i;
				}
            }
				if(mini==INT_MAX){
					curr_t++;
				}
				else{
					if(time_remain[curr_proc]<=time_slice){
						fi[curr_proc] = 1;
						ct[curr_proc] = curr_t + time_remain[curr_proc];
						curr_t +=time_remain[curr_proc];
						t++;
						tat[curr_proc] = ct[curr_proc] - at[curr_proc];
						wt[curr_proc] = tat[curr_proc] - bt[curr_proc];
						time_remain[curr_proc] = 0;
					}
					else{
						time_remain[curr_proc] = time_remain[curr_proc] - time_slice;
						curr_t +=time_slice;
					}
				}
			}
        

			for(int i=0;i<5;i++){
				avgwt += wt[i];
				avgta+= tat[i];
			}
			avgwt = avgwt/n;
			avgta = avgta/n;

			cout<<"Process"<<" "<<"AT"<<" "<<"BT"<<" "<<"WT"<<"\n";
			for(int i=0;i<5;i++){
				cout<<pid[i]<<" "<<at[i]<<" "<<bt[i]<<" "<<wt[i]<<"\n";
			}
			cout<<"Average Waiting time is"<<" "<<avgwt<<"\n";
				cout<<"Average Turn Around Time is"<<" "<<avgta<<"\n";

		

return 0;
}