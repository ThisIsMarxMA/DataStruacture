void Insert(int x,Sqlist &Va){
	for(int i=0;i<Va.length;i++){
		if(Va.Elem[i]>x){
			break;
		}
	}
	ListInsert(Va,i,x);
}


 Status ListInsert(Sqlist &L,int i,Elemtype e){
 	if(i<1||i>L.length+1)return ERROR;
 	if(L.length>=L.listsize){
 		newbase=(Elemtype *)realloc(L.Elem,(L.listsize+LISTINCREMENT)*sizeof(Elemtype));
 		if(!newbase)exit(overflow);
 		L.Elem=newbase;
 		L.listsize+=LISTINCREMENT;
 	}
 	q=&(L.Elem[i-1]);
 	for(p=&(L.Elem[L.length-1]);p>=q;--p)
 		*(p+1)=*p;
 	*q=e;
 	++L.length;
 	return OK;
 }

 