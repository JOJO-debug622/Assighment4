# Assighment4：Matrix

## 功能：

* 使用class来定义储存Matrix的行数、列数和元素。
* 重新定义运算符号+、-、*、=。
-----
代码：

### * class：
```cpp
class Matrix {
private:
	int rows;
	int columns;
	float** m;

public:
	
	Matrix(int a, int b);
	Matrix(float** M);
	~Matrix();
	Matrix operator +(const Matrix& other);
	Matrix operator -(const Matrix& other);
	friend Matrix operator *(float real, const Matrix& other);
	Matrix operator *(const Matrix& other);
	Matrix operator *(const float a);
	friend std::ostream& operator <<(std::ostream& os, const Matrix& other);
	Matrix& operator =(const Matrix& other);

};
```
### * 构造函数：
```cpp
Matrix::Matrix(int a, int b) : rows(a), columns(b) {
	m = new float* [rows];
	for (int i = 0; i < rows; i++) {
		m[i] = new float[columns];
		
	}

}

Matrix::Matrix(float** M) : rows(_msize(M)/sizeof(M[0])), columns(_msize(*M)/sizeof(m[0][0])) {
	m = new float* [rows];
	for (int i = 0; i < rows; i++) {
		m[i] = new float[columns];
		for (int j = 0; j < columns; j++) {
			m[i][j] = M[i][j];
		}
	}

}
```
* 其中Matrix（a，b）生成一个a行b列的矩阵，并初始定义所有元素为0；Matrix（**m）直接生成一个与二维数组相同的矩阵；
### * 重载符号：
```cpp
std::ostream& operator <<(std::ostream& os, const Matrix& other) {
	os << other.rows << "*" << other.columns << "矩阵：" << endl;
	for (int i = 0; i < other.rows; i++) {
		for (int j = 0; j < other.columns; j++) {
			os << other.m[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

Matrix& Matrix::operator=(const Matrix& other) {
	rows = other.rows;
	columns = other.columns;
	delete[] m;
	m = other.m;
	return *this;
}

Matrix operator *(const float a,const Matrix& other) {
	Matrix S(other.rows, other.columns);
	for (int i = 0; i < other.rows; i++) {
		for (int j = 0; j < other.columns; j++) {
			S.m[i][j] = a * other.m[i][j];
		}
	}
	return S;
}

Matrix Matrix::operator *(const float a) {
	Matrix S(rows,columns);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			S.m[i][j] = a * m[i][j];
		}
	}
	return S;
}

Matrix Matrix::operator+(const Matrix& other) {
	Matrix S(rows,columns);
	if (this->rows == other.rows && this->columns == other.columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				S.m[i][j] = this->m[i][j] + other.m[i][j];
			}
		}

		return S;
	}
	else {
		cout << "这两个矩阵无法相加！";
	}
}

Matrix Matrix::operator -(const Matrix& other) {
	Matrix S(rows, columns);
	if (this->rows == other.rows && this->columns == other.columns) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				S.m[i][j] = this->m[i][j] - other.m[i][j];
			}
		}

		return S;
	}
	else {
		cout << "这两个矩阵无法相加！";
	}
}

Matrix Matrix::operator *(const Matrix& other) {
	Matrix S(rows, other.columns);
	if (this->columns == other.rows) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < other.columns; j++) {
				S.m[i][j] = 0;
				for (int a = 0; a < columns; a++) {
					S.m[i][j] += m[i][a] * other.m[a][j];
				}
			}
		}

		return S;
	}
	else {
		cout << "这两个矩阵无法相乘！";
	}
}
```

### * 主程序：
```cpp
int main() {
	
	float** M;
	float** m;
	M = new float* [3];
	for (int i = 0; i < 3; i++) {
		M[i] = new float[3];
		for (int j = 0; j < 3; j++) {
			M[i][j] = 2; 
		}
	}

	m = new float* [3];
	for (int i = 0; i < 3; i++) {
		m[i] = new float[3];
		for (int j = 0; j < 3; j++) {
			m[i][j] = 1;
		}
	}


	Matrix m1(m);
	Matrix m2(M);
	Matrix m3 = m2;
	cout << m1 << endl;
	cout << m2 << endl;
	cout << m3 << endl;
	cout << Matrix(m) + Matrix(M) << endl;
	cout << m2 - m1<<endl;
	cout << m2 * m1 << endl;
	cout << 3 * m2 << endl;
	cout << m2 * 3 << endl;

}
```
* 生成两个3*3的矩阵，并进行各种运算。

### * 结果截图：
![] 
(https://github.com/JOJO-debug622/Assighment4/blob/main/Assignment4.PNG)
