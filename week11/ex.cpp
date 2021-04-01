#include <bits/stdc++.h>

using namespace std;

bool check(vector < vector <char> > &a){
    bool res=false;
    for(int i=0;i<3;i++){
        bool good=true;
        for(int j=0;j<3;j++){
            if(a[i][j]==' ' || a[i][j]!=a[i][0]){
                good=false;
            }
        }
        if(good) res=true;
    }
    for(int i=0;i<3;i++){
        bool good=true;
        for(int j=0;j<3;j++){
            if(a[j][i]==' ' || a[j][i]!=a[0][i]){
                good=false;
            }
        }
        if(good) res=true;
    }
    if(a[0][0]!=' ' && a[0][0]==a[1][1] && a[0][0]==a[2][2]) res=true;
    if(a[0][2]!=' ' && a[0][2]==a[1][1] && a[0][2]==a[2][0]) res=true;
    return res;
}

map < vector < vector <char> >,int> result;

int solve(vector < vector <char> > &a,int turn=0){
    if(result.count(a))
        return result[a];
    if(check(a)) return -1;
    int res=-1;
    bool wasmove=false;
    for(int i=0;i<3;i++){
        if(res==1) break;
        for(int j=0;j<3;j++){
            if(a[i][j]==' '){
                wasmove=true;
                if(turn==0)
                    a[i][j]='X';
                else
                    a[i][j]='O';
                int k=solve(a,1-turn);
                a[i][j]=' ';
                if(k==-1)
                    res=1;
                else if(k==0 && res!=1)
                    res=0;
            }
        }
    }
    if(!wasmove) res=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    cout<<res<<endl<<endl;
    result[a]=res;
    return res;
}

int main(){
    vector < vector <char> > a(3,vector <char> (3,' '));
    int turn=0;
    cout<<solve(a,turn);
    return 0;
}
