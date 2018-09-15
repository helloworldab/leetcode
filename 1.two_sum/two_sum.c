int *twoSum(int* nums,int numsize,int target){
	int i,j;
	int *p=NULL;
	p=(int*)malloc(2*sizeof(int));
	for(i=0;i<numsize;i++){
		for(j=i+1;j<numsize;j++){
			if((nums[i]+nums[j])==target){
				p[0]=i;
				p[1]=j;
				return p;
			}
		}
	}
	return p;
}
