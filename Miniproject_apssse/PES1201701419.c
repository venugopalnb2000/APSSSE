#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include"intal.h"


static char* add(const char *intal1,const char *intal2){
    int n1=strlen(intal1);
    int n2=strlen(intal2);

    // printf("%s \n%s \n",intal1,intal2 );
    int n=n1-n2;

    // int *arr = (int*)calloc(sizeof(int),n);
    char *s = (char*)malloc(sizeof(char)*(n1+2));
    char *s1= (char*)malloc(sizeof(char)*(n1+2));

    int j=0;

    int c=0;

    int sum;
    for(int i=n2-1;i>=0;i--,j++){
        sum=intal1[i+n]-'0'+intal2[i]-'0'+c;
        s[j]=(sum%10)+'0';

        c=sum/10;

    }

    // printf("%s %d \n",s,j );
    for(int i=n-1;i>=0;i--,j++){
        sum=intal1[i]-'0'+c;
        s[j]=(sum%10)+'0';

        c=sum/10;
    }

    // printf("%s\n",s );
    while(c>0){
        // sum='0'+c;
        s[j]=(c%10)+'0';
        j++;
        c=c/10;
    }

    // s[j]='\0';
    // printf("%d\n",j );
    for(int i=0;i<j;i++){
        s1[i]=s[j-i-1];
    }
    s1[j]='\0';
    free(s);
    return s1;

}

char* intal_add(const char* intal1, const char* intal2){
    int n1=strlen(intal1);
    int n2=strlen(intal2);


    if(n1<n2) return add(intal2,intal1);
    return add(intal1,intal2);

}


///////////////////////////////////////////////////////////////

int intal_compare(const char* intal1, const char* intal2){

	int n1,n2;
	n1=strlen(intal1);
	n2=strlen(intal2);

	char i1[n1],i2[n2];
	strcpy(i1,intal1);
	strcpy(i2,intal2);

	char *s1;
	char *s2;

	int i=0;
	while(i<n1){
		if(i1[i]=='0') i++;
		else break;
	}

	s1=&i1[i];
	i=0;
	while(i<n2){
		if(i2[i]=='0') i++;
		else break;
	}

	s2=&i2[i];


	// printf("i1 %s i2 %s \n",s1,s2 );
	// printf("i1 %s i1 ",i1 );
	if(strlen(s1)>strlen(s2) ) return 1;
	else if(strlen(s1)<strlen(s2)) return -1;
	if(strlen(s1)==0 && strlen(s2)==0) return 0;
	else if(strcmp(s1,s2)==0) return 0;
	else{
		i=0;
		while(i<strlen(s1)){
			if(s2[i]>s1[i]) return -1;
			else if (s1[i]>s2[i]) return 1;
			i++;
		}
		return 0;
	}
}

/////////////////////////////////////////////////////////////////////////////////

static char* diff(const char *intal1,const char *intal2){


	int n1=strlen(intal1);
	int n2=strlen(intal2);


	int n=n1-n2;

	char *s=(char *)malloc(sizeof(char)*n1);
	char *s1=(char *)malloc(sizeof(char)*n1);


	int k=0;

	int c=0;

	for(int i=n2-1;i>=0;i--){
		int sub=(intal1[i+n]-'0')-(intal2[i]-'0')-c;
		// printf("s %d\n",s );

		if(sub<0){
			sub=sub+10;
			c=1;
		}
		else{
			c=0;
		}
		// char t=s+'0';
		// strncat(fin,&t,1);
		s[k]=sub+'0';
		k++;
	}

	for(int i=n-1;i>=0;i--){
		if(intal1[i]=='0' && c){
			s[k]='9';
			k++;
			continue;
		}
		int sub=(intal1[i]-'0')-c;
		if(i>0 || sub>0){
			s[k]=sub+'0';
			k++;
		}
		c=0;
	}

	// printf("%s\n",fin );

	for(int i=0;i<k;i++){
		s1[i]=s[k-i-1];
	}
	free(s);
	s1[k]='\0';
	return s1;

}

char* intal_diff(const char* intal1, const char* intal2){

	int cmp=intal_compare(intal1,intal2);
	char *fin;

	// printf("%d\n",cmp );


	if(cmp==0){
		fin=(char *)malloc(sizeof(char)*1);
		strcpy(fin,"0");
		return fin;
	}
	if(cmp==-1){
		// strcpy(fin,"");
		fin=diff(intal2,intal1);
	}
	else{
		// strcpy(fin,"");
		fin=diff(intal1,intal2);
	}

	char *p=(char *)malloc(sizeof(char)*(strlen(fin)));
	int i=0;
	while(fin[i]=='0') i++;
	// printf("%d\n",i );
	for(int j=0;j<=strlen(fin)-i;j++){
		p[j]=fin[i+j];
	}
	// printf("%s\n",p );
	return p;
}


char* intal_multiply(const char* intal1, const char* intal2)
{
	long long n1 = strlen(intal1);
    long long n2 = strlen(intal2);
    long long n = n1+n2;
    int *arr = (int*)calloc(sizeof(int),n);
	char *s = (char*)malloc(sizeof(char)*(n+1));

    if(*intal1=='0' || *intal2=='0'){
		s[0] = '0';
		free(arr);
		return s;
	}
     
    for(long long i=n1-1; i>=0; i--){
        for(long long j=n2-1; j>=0; j--){
            arr[i+j+1] += (intal1[i]-'0')*(intal2[j]-'0');
		}
	}
    for(long long i=n-1; i > 0; i--){
        arr[i-1] += arr[i]/10;
        arr[i] %= 10;
    }
    long long index = 0;
    long long i = 0;
    if(arr[i]==0)
		i++;
    while(i < n)
        s[index++] = arr[i++]+'0';
    s[index] = '\0';
	free(arr);
    return s;
}



char* intal_mod(const char* intal1, const char* intal2){

	int n1=strlen(intal1);
	int n2=strlen(intal2);

	char *i1=(char *)malloc(sizeof(char)*n1);

	strcpy(i1,intal1);

	char *p;

	int cmp=intal_compare(i1,intal2);

	if(intal_compare("0",intal2)==0){
		strcpy(i1,"Cannot be divided by 0");
		return i1;
	}
	if(cmp==-1) return i1;

	else if(cmp==0){
		strcpy(i1,"0");
		return i1;
	}
	p=(char *)malloc(sizeof(char)*(n1+n2));
	strcpy(p,"");
	int i=0;

	int k=0;

	while(i<n1){
		k=strlen(p);
		while(i<n1 && intal_compare(p,intal2)<0){
			p[k]=i1[i];
			i++;
			k++;
		}
		p[k]='\0';
		while(intal_compare(p,intal2)>=0){
			p=intal_diff(p,intal2);
		}
		if(strcmp(p,"0")==0){
			strcpy(p,"");
		}

	}

	int j;

	for(j=0;j<strlen(p);j++){
		if(p[j]!='0') break;
	}

	free(i1);
	if(j==strlen(p)){
		p[0]='0';
		p[1]='\0';
		return p;
	}
	for(i=0;i<strlen(p)-j;i++){
		p[i]=p[j-i];
	}
	p[i]='\0';
	return p;

}



char* intal_pow(const char* intal1, unsigned int n){

	if(n==0) return "1";
	char *temp=intal_pow(intal1,n/2);

	if(n%2==0) return intal_multiply(temp,temp);

	else{
		char *t2=intal_multiply(temp,temp);
		return intal_multiply(t2,intal1);
	}


}


/////////////////////////////////////////////////////////////////

// char *gcd()

char* intal_gcd(const char* intal1, const char* intal2){
	char *it1=(char *)malloc(sizeof(char)*1001);
	char *it2=(char *)malloc(sizeof(char)*1001);
	char *temp=(char *)malloc(sizeof(char)*1001);
	// char *it2;

	strcpy(it1,intal1);
	strcpy(it2,intal2);

	// printf("%s %s \n",it1,it2 );
	int cmp=intal_compare(it2,"0");

	while(cmp>0){
		temp=intal_mod(it1,it2);

		// printf("mod %s\n",temp );
		it1=it2;
		it2=temp;
		cmp=intal_compare(it2,"0");
	}
	free(temp);
	// free(it2);
	return it1;
	

}

///////////////////////////////////////////////////////////////


char* intal_fibonacci(unsigned int n){
	

	char *a,*b,*c;
	a=(char *)malloc(sizeof(char)*INT_MAX);
	b=(char *)malloc(sizeof(char)*INT_MAX);
	c=(char *)malloc(sizeof(char)*INT_MAX);
	a="0";
	b="0";
	c="1";


	// printf("hi\n" );
	if(n==0) return a;
	for (int i = 1; i < n; i++){ 
		a=b;
		b=c;

		c=intal_add(a,b);


  } 
  c=intal_add(a,b);
  free(b);
  // free(a);
  return c; 

}


/////////////////////////////////////////////////////////////////


char* intal_factorial(unsigned int n){
	if(n==0) return "1";
	char *st=(char *)malloc(sizeof(char)*INT_MAX);
	char *fact=(char *)malloc(sizeof(char)*INT_MAX);
	fact="1";
	for(unsigned int i=1;i<=n;i++){
		sprintf(st,"%d",i);
		fact=intal_multiply(fact,st);
	}
	return fact;
}



///////////////////////////////////////////////////////////////


int intal_max(char **arr, int n){
	int max=0;

	int cmp;

	for(int i=1;i<n;i++){
		cmp=intal_compare(arr[max],arr[i]);
		if(cmp==-1) max=i;
	}

	return max;

}

//////////////////////////////////////////////////////////////

int intal_min(char **arr, int n){
	int min=0;

	int cmp;

	for(int i=1;i<n;i++){
		cmp=intal_compare(arr[min],arr[i]);
		if(cmp==1) min=i;
	}

	return min;

}

///////////////////////////////////////////////////////////////

char* intal_bincoeff(unsigned int n, unsigned int k){
	if(k>n) return "";
	if(k>n-k) k=n-k;
	// if(k==0 || k==n)
	char **p=(char **)malloc(sizeof(char *)*(k));

	p[0]="1";

	for(int i=1;i<=k;i++) {
		// p[i]=(char *)malloc(sizeof(char)*10001);
		p[i]="0";
	}



	for (int i = 1; i <= n; i++){ 
		for (int j = (i<k?i:k); j > 0; j--) 
	   		p[j] = intal_add(p[j],p[j-1]); 
    } 

    char *cof=(char *)malloc(sizeof(char)*strlen(p[k]));
    strcpy(cof,p[k]);
    // for(int i=0;i<k;i++) free(p[i]);
    free(p);
    return cof;
}
//////////////////////////////////////////////////////////////

char* coin_row_problem(char **arr, int n){
	char *incl = arr[0]; 
	char *excl = "0"; 
  	char *excl_new; 
  	int i; 

  	int cmp;
  
  	for (i = 1; i < n; i++){ 

  		cmp=intal_compare(incl,excl);
  		if(cmp>0) excl_new=incl;
  		else excl_new=excl;
  		incl = intal_add(excl,arr[i]); 
  		excl = excl_new; 
  	} 
  	cmp=intal_compare(incl,excl);
  	if(cmp>0) return incl;
  	return excl;
}

///////////////////////////////////////////////////////////////

int intal_search(char **arr, int n, const char* key){

	for(int i=0;i<n;i++){
		if(intal_compare(arr[i],key)==0) return i;
	}
	return -1;

}
/////////////////////////////////////////////////////////////////

static void merge(char **arr, int l, int m, int r) 
{ 

	// printf("%s\n",arr[0] );
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    char* L[n1];
    char* R[n2]; 
  
    for (i = 0; i < n1; i++){
        L[i]=arr[l + i]; 
    }
    for (j = 0; j < n2; j++) 
        R[j]=arr[m + 1+ j]; 

   
    i = 0;  
    j = 0; 
    k = l;  
    while (i < n1 && j < n2) 
    { 
        if (intal_compare(L[i],R[j])<=0) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

static void mergeSort(char **arr, int l, int r) 
{ 
    if (l < r) 
    { 
       
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 



void intal_sort(char **arr, int n){
	mergeSort(arr,0,n-1);
}



////////////////////////////////////////////////////////////////


static int bs(char **arr, int l, int r, const char* x) 
{ 
	int cmp;
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        cmp=intal_compare(arr[m],x);
        if (cmp==0) 
            return m; 
  
        if (cmp==-1) 
            l = m + 1; 
  
        else
            r = m - 1; 
    } 
  
    return -1; 
} 


int intal_binsearch(char **arr, int n, const char* key){
	intal_sort(arr,n);
	return bs(arr,0,n-1,key);
}
