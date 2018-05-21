ADT Array
{
	InitArray(&A,n,bound1,...,boundn);
		//初始化一个数组A,具有n个维,各维分别具有长度boundn
	DestoryArray(&A);
		//销毁数组A
	Value(A,&e,index1,index2,...);
		//取出数组指定位置值
	Assign(&A,e,index1,...,indexn);
		//给数组的指定位置赋值
}ADT Array
		//行主序二维数组任意元素a(i,j)的地址
		//每个数据元素占L个存储单元
		//LOC(i,j)=LOC(0,0)+(b2xi+j)*L
		//LOC(j1,j2,...jn)=LOC(0,0,...0)+(b2*...*bn*j1+b3*...*bn*j2+...+bn*jn-1+jn)*L