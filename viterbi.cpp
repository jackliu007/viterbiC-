# include <iostream>
# include <string>
# include <list>

using namespace std;

int main(){ 
	double pi[3] = { 0.2,0.4,0.4};
	double a[3][3] = {{0.5,0.2,0.3},{0.3,0.5,0.2},{0.2,0.3,0.5}};
	double b[3][2] = {{0.5,0.5},{0.4,0.6},{0.7,0.3}};
	
	string output[3] = {"r","w","r"};
	int out[3];
	double delta[3][3] = {0};
	double path[3][3] = {0};
	int row = 3;
	int column = 3;
	int i,j,k;
	//将输出状态转为数组
	for( i = 0 ; i < row ; i++){ 
		if(output[i] == "r")
			out[i] = 0 ; 
		else if (output[i] == "w")
			out[i] = 1;
	} 
	//初始化
	for( i = 0 ; i < row ; i++){
		delta[i][0] = pi[i] * b[i][0];
		path[i][0] = 0;
		cout << delta[i][0] << endl;
	}
	//递归
	for( j = 1 ;  j < column ; j++){ //序列遍历，矩阵列遍历
		for( k = 0 ; k < column ; k++){ //状态遍历
				double pro = 0 ;
				int sta  = 0 ; 
				for( i = 0 ; i < row ; i++){//矩阵行遍历
					double temp = delta[i][j-1] * a[i][k]*b[k][out[j]];
					cout << delta[i][j - 1] << " " <<b[k][out[j]] << endl;
					cout << temp << endl;
					if(temp > pro){
						pro = temp; 
						sta = i; //记录路径信息
					}
				}
				delta[k][j] = pro;
				path[k][j] = sta ;
		}
	}
	//终止，找到概率最大值
	double max = 0 ; 
	int sta = 0 ; 
	for( i = 0 ; i < row ; i++){ 
		if(delta[i][column-1] > max) { 
			max = delta[i][column - 1];
			sta =  i ;
		}
	}
	// 回溯，找到最大路径及其对应的状态值
	list<int> listPath ;
	listPath.push_back(sta + 1);
	for( j = column - 1 ; j > 0 ; j--){ 
		sta = path[sta][j];
		listPath.push_back(sta + 1);
	}
	//输出
	cout << "max probability: " << max << endl;
	list<int>::iterator itepath ;
	for( itepath = listPath.begin() ; itepath != listPath.end() ; itepath++)
		cout << *itepath << " " ;
	cout<<endl;
	return 0;
}
