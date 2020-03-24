#include <vector>
#include <math.h>

using namespace std;

typedef vector<float> Vector;
typedef vector<Vector> Matrix;

void zeroes(Vector &v, int n){
    for(int i=0; i<n; i++)
        v.push_back(0.0);

}
void zeroes(Matrix &M, int n){
    for(int i=0; i<n; i++) {
        Vector row(n, 0.0);
        M.push_back(row);
    }

}

void copyVector(Vector v, Vector &copy){
    zeroes(copy, v.size());
    for(int i=0; i<v.size(); i++){
        copy.at(i) = v.at(i);
    }

}
void copyMatrix(Matrix A, Matrix &copy){
    zeroes(copy, A.size());
    for(int i=0; i<A.size();i++)
        for(int j=0; j<A.at(0).size();j++)
            copy.at(i).at(j) = A.at(i).at(j);

}

void productMatrixVector(Matrix A, Vector v, Vector &R){
    for(int fila=0; fila<A.size(); fila++) {
        float cell = 0.0;
        for (int col = 0; col < v.size(); col++)
            cell += A.at(fila).at(col);
        R.at(fila) += cell;
    }
}


void getMinor(Matrix &M,int i, int j){
    M.erase(M.begin()+i);
    for(int i=0;i<M.size();i++)
        M.at(i).erase(M.at(i).begin()+j);
}

float determinant(Matrix M){
    if(M.size() == 1) return M.at(0).at(0);
    else{
        float det=0.0;
        for(int i=0;i<M.at(0).size();i++){
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,0,i);
            det += pow(-1,i)*M.at(0).at(i)*determinant(minor);
        }
        return det;
    }
}

void cofactors(Matrix M, Matrix &Cof){
    zeroes(Cof,M.size());
    for(int i=0;i<M.size();i++){
        for(int j=0;j<M.at(0).size();j++){
            Matrix minor;
            copyMatrix(M,minor);
            getMinor(minor,i,j);
            Cof.at(i).at(j) = pow(-1,i+j)*determinant(minor);
        }
    }
}

void transpose(Matrix M, Matrix &T){
    //zeroes(T,M.size());
    for(int i=0;i<M.size();i++)
        for(int j=0;j<M.at(0).size();j++)
            T.at(j).at(i) = M.at(i).at(j);

}

void inverse(Matrix M, Matrix &I){
    float det = determinant(M);
    if(det == 0){
        cout<<"el determinante es 0 y por lo tanto la matriz no tiene inversa";
        cout<<endl;
        cout<<endl;
        exit(EXIT_FAILURE);
    }else {
        cofactors(M, I);

        transpose(I, I);

        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M.size(); j++)
                I.at(i).at(j) = I.at(i).at(j) / det;
        }
    }
}