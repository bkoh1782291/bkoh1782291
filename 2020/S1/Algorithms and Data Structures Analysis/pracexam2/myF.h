#ifndef MYF_H
#define MYF_H

class myF
{
public:

	myF();
	~myF();

	//methods
    int solve(int n);
    //int solve_mem(int *mem_array, int n);
    int solve_mem(int *temparr, int n);
};

#endif 
/*
	string flag;

	int arr[7];

	cin >> flag;

    for (int i=0; i<7; i++){
    	cin >> arr[i];
    }

    root = b.Insert(root, arr[0]);
    
    for(int i=0; i<7; i++){
    	b.Insert(root, arr[i]);
    }

    if (flag == "BIN"){
		b.Inorder(root); 	
	}
*/