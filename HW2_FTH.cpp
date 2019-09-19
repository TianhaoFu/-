#include<iostream> 
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;
//csv文件其实就是文本文件，每行字段用逗号分隔。
int main()
{
	ifstream inFile("iris_data.csv", ios::in);
	string lineStr;
	vector < vector  < string > > strArray;
	if ( inFile.fail())
		cout << "读取文件失败" << endl;
	while ( getline(inFile,lineStr)) 
	{
//		打印整行字符串 
//		cout << lineStr << endl;
		stringstream ss(lineStr) ;
		string str;
		vector < string > lineArray ;
		while ( getline(ss,str,','))
			lineArray.push_back(str);
		strArray.push_back(lineArray);
	}
	getchar() ;
//	检查数据格式 
//	for(int i = 0 ; i < strArray.size() ; i  ++ )
//	{
//		for ( int j = 0 ; j < strArray[i].size() ; j ++ )
//		{
//			cout << "----" <<strArray[i][j];
//		}
//		cout << endl;
//	}
//
	int n = strArray.size();
	int min[5],max[5],media[5],q1[5],q3[5];
	
	for(int i = 1 ; i < 5 ; i ++)
	{
		int a[n+1];    
		for(int j = 1 ; j <= n ; j ++ )
		{
			int num;
			stringstream ss1(strArray[i][j]);
			ss1>>num;
			a[j] = num;
		}
		sort(a[1],a[n]);
		min[i] = a[1];
		max[i] = a[n];
		media[i] = (a[n/2] + a[n/2+1])/2;
		int loc1 = (n/2)/2 + 1;
		//不是整数
		int loc3 = (n/2+1) + (( n - (n/2+1) + 1) / 2);
		//不是整数 
//		长度 ：末-初+1
		//中位数 首 + 长度/2 （此题中非整数） 
		q1[i] = a[loc1] ;
		q3[i] = a[loc3] ;	
	}
	ofstream outFile;
	outFile.open("iris_data_processed.csv",ios::out);
	cout<<"attribute_name"<<"min"<<"q1"<<"mean"<<"q3"<<"max"<<endl;
	outFile << "萼片长度（cm）"<<min[1]<<q1[1]<<media[1]<<q3[1]<<max[1]<<endl; 
	outFile << "萼片宽度（cm）"<<min[2]<<q1[2]<<media[2]<<q3[2]<<max[2]<<endl;
	outFile << "花瓣长度（cm）"<<min[3]<<q1[3]<<media[3]<<q3[3]<<max[3]<<endl;
	outFile << "花瓣宽度（cm）"<<min[4]<<q1[4]<<media[4]<<q3[4]<<max[4]<<endl;
	outFile.close();
	return 0 ;
	
}
