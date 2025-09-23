 class Solution {
 public:
 int compareVersion(string version1, string version2) {
    vector<string> v1 = removedots(version1, '.'); //preprocess string 1
	vector<string> v2 = removedots(version2, '.'); //preprocess string 2
    
    int i=0, j=0;
    
    while (i<v1.size() and j<v2.size()){ //traverse both the strings using two pointers
        int e1 = stoi(v1[i++]); //keep on storing the integers at index i
        int e2 = stoi(v2[j++]); //keep on storing the integer at index j
        if(e1>e2) return 1; //if you find first integer is big than second, return 1
        else if(e1<e2) return -1; //else if if you find first is small then second return -1
    }
    while (i<v1.size()) if(stoi(v1[i++])>0) return 1; //v1 to be traversed, check if remaining part is greater than 0
    while (j<v2.size()) if(stoi(v2[j++])>0) return -1;//v2 to be traversed, check if remaining part is greater than 0
    return 0; //this means both are equal
    
    
}
    vector<string> removedots(string str, char dot){ //utility to remove dots
    vector<string> preprocessed; //will store the preprocessed string after operation
    stringstream ss(str); //to read strings delimiter by delimiter
    string i; //empty string to be passed
    while (getline(ss, i, dot)) preprocessed.push_back(i); //we will add the characters removing dots
    return preprocessed; //return the preprocessed
}
};