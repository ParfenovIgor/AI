#include <bits/stdc++.h>

using namespace std;

int w,h,startTime=time(0);

char randDir(){
    int k=rand()%4;
    if(k==0)
        return 'D';
    if(k==1)
        return 'U';
    if(k==2)
        return 'L';
    if(k==3)
        return 'R';
    return 'U';
    assert(false);
}

int cost(vector <char> &path){
    vector < vector <bool> > used(w,vector <bool> (h));
    int x=0,y=0;
    used[0][0]=true;
    for(int i=0;i<path.size();i++){
        if(path[i]=='D'){
            y--;
            if(y==-1 || used[x][y]) return i;
        }
        if(path[i]=='U'){
            y++;
            if(y==h || used[x][y]) return i;
        }
        if(path[i]=='L'){
            x--;
            if(x==-1 || used[x][y]) return i;
        }
        if(path[i]=='R'){
            x++;
            if(x==w || used[x][y]) return i;
        }
        used[x][y]=true;
    }
    return path.size();
}

vector <char> cross(vector <char> &path1,vector <char> &path2){
    vector <char> res(w*h);
    for(int i=0;i<w*h;i++){
        if(path1[i]==path2[i]) res[i]=path1[i];
        else res[i]=randDir();
    }
    return res;
}

int main(){
    cin>>w>>h;
    vector <char> path(w*h,'U');

    const int N=5000,M=5000;
    for(int tt=0;tt<N;tt++){
        vector < vector <char> > new_path(M);
        for(int i=0;i<M;i++){
            new_path[i]=path;
            new_path[i][rand()%(w*h)]=randDir();
        }
        vector < pair <int,int> > costs(M);
        for(int i=0;i<M;i++){
            costs[i]={cost(new_path[i]),i};
        }
        sort(costs.rbegin(),costs.rend());
        path=cross(new_path[costs[0].second],new_path[costs[1].second]);

        cout<<setfill(' ')<<setw(3)<<(int)((tt+1)*100/N)<<setw(0);
        cout<<"% done. ";
        cout<<setfill(' ')<<setw(6)<<(time(0)-startTime)*(N-(tt+1))/(tt+1)<<setw(0);
        cout<<" seconds remaining.\r";
    }

    cout<<"Successful execution. Run time "<<(time(0)-startTime)<<" seconds.\n";

    cout<<cost(path)+1<<"/"<<w*h<<" cells visited\n";
    for(int i=0;i<cost(path);i++){
        cout<<path[i];
    }
    cout<<'\n';

    return 0;
}
