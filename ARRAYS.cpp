#include <iostream>
#include <fstream>

using namespace std;
int const N = 3;

double horner(int x, int* arr);
bool is_simple(int x);
void Buble_sort(int arr[]);
void shake_sort(int* arr);
void sort_with_max_po_vozr(int* arr);
void sort_with_min_po_vozr(int* arr);
void sort_with_min_po_ubiv(int* arr);
void sort_with_max_po_ubiv(int* arr);
void slianie(int* arr1, int* arr2, int* res);
void sort_vstavkoi(int* arr);
void proizv(int arr[], int ans[]);
void umn_mn(int arr1[], int arr2[], int ans[]);
void sum_mn(int arr1[], int arr2[], int ans[]);
void raznost_arr(int arr1[], int arr2[], int ans[],int &k);
void peresech_arr(int arr1[], int arr2[], int ans[], int& k);
void triangle_matrix(int arr[][N]);
void make_null_matrix(int arr[][N]);
void out_matrix(int arr[][N], ofstream& out);
int** create_matrix(ifstream& in, int n, int m);
void show_matrix(int** arr, int n, int m, ofstream& out);
int find_max(int** arr, int n, int m);
void swap_min_max(int** arr, int n, int m);
void swap_min_max_col(int** arr, int n, int m);

int main() {
    // дз 1a, 4а, 6, 11(a,b), 13(a)(e), 22(a)(b)(ж) 
    // 13 вгдж, (8aбв), 15аб
    // пузырьковая, шейкерная, 22з
    // сорт поиском минимумом максимумом по возр и по убыв, слиянием, вставкой, обменом 
    //решето эратосфена
    // пересечение массивов и разность, сложение мнгочленов взятие произв взятие первообразной
    // схема горнера через fstream, уножение число многочленов
    // 
    //1a
    
    //int arr_a[N], arr_b[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr_a[i];
    //for (int i = 0; i < N; i++)
    //    cin >> arr_b[i];
    //int ans = 0;
    //for (int i = 0; i < N; i++)
    //    ans += arr_a[i] * arr_b[i];
    //cout << ans;

    //4
    
    //int max, min, min_id, max_id;
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //max = arr[0];
    //min = arr[0];
    //min_id = 0;
    //max_id = 0;
    //for (int i = 1; i < N; i++) {
    //    if (arr[i] > max) {
    //        max = arr[i];
    //        max_id = i;
    //    }
    //    if (arr[i] < min) {
    //        min = arr[i];
    //        min_id = i;
    //    }
    //}
    //cout << "min = " << min << "[" << min_id << "]" << '\n';
    //cout << "max = " << max << "[" << max_id << "]" << '\n';

    //11a
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int y[N];
    //int t;
    //for (int i = 0; i < N; i++) {
    //    y[i] = arr[N - 1 - i];
    //}
    //for (int j = 0; j < N; j++)
    //    cout << y[j] << ' ';

    //11b
    
    //  int arr[N];
    // for (int i = 0; i < N; i++)
    //    cin >> arr[i];    
    //int y[N];
    //y[0] = arr[N - 1];
    //for (int i = 1; i < N; i++) {
    //    y[i] = arr[i - 1];
    //}
    //for (int j = 0; j < N; j++)
    //    cout << y[j] << ' ';

    //13a
    
    // int arr[N];
    // for (int i = 0; i < N; i++)
    //    cin >> arr[i];    
    //int c = 1;
    //int fl = arr[0];
    //for (int i = 1; i < N - 1; i++) {
    //    if (arr[i] < arr[i + 1])
    //        c++;
    //}
    //cout << c;

    //13e
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int c = 0;
    //if (arr[0] != arr[1])
    //    c++;
    //for (int i = 1; i < N - 1; i++) {
    //    if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
    //        c++;
    //}
    //if (arr[N - 1] != arr[N - 2])
    //    c++;
    //cout << c;

    //6
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int y[N], z[N];
    //y[0] = 0;
    //z[0] = 0;
    //for (int i = 1; i < N; i++) {
    //    if (arr[i] * arr[i - 1] < 0)
    //        y[i] = 1;
    //    else
    //        y[i] = 0;
    //    if (arr[i - 1] > arr[i])
    //        z[i] = 1;
    //    else
    //        z[i] = 0;
    //}
    //for (int i = 0; i < N; i++)
    //    cout << y[i] << " ";
    //cout << endl;
    //for (int i = 0; i < N; i++)
    //    cout << z[i] << ' ';

    //22а
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int S_pol, S_otr;
    //S_pol = S_otr = 0;
    //for (int i = 0; i < N; i++)
    //    if (arr[i] > 0)
    //        S_pol += arr[i];
    //    else
    //        S_otr += arr[i];
    //cout << "S(+) = " << S_pol << '\n';
    //cout << "S(-) = " << S_otr << '\n';
    
    //22б
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int c = 0;
    //for (int i = 1; i < N; i++) {
    //    if ((arr[i] >= 0 && arr[i - 1] < 0) || (arr[i] < 0 && arr[i - 1] >= 0))
    //        c++;
    //}
    //cout << c;

    //22ж
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int c = 0;
    //for (int i = 0; i < N; i++) {
    //    if (is_simple(arr[i]))
    //        c++;
    //}
    //cout << c;
    //return 0;   


    //13в
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int arr_v[N];
    //for (int i = 0; i < N; i++)
    //    arr_v[i] = 0;
    //int c = 0;
    //int len = 1;
    //for (int i = 0; i < N - 1; i++) {
    //    if (arr[i] == arr[i + 1])
    //        len++;
    //    else {
    //        arr_v[len - 1]++;
    //        len = 1;
    //    }
    //}
    //arr_v[len - 1]++;
    //for (int i = 0; i < N; i++)
    //    cout << arr_v[i] << " ";

    //13г
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int arr_v[N];
    //for (int i = 0; i < N; i++)
    //    arr_v[i] = 0;
    //int c = 0;
    //int len = 1;
    //for (int i = 0; i < N - 1; i++) {
    //    if (arr[i] == arr[i + 1])
    //        len++;
    //    else {
    //        arr_v[c] = len;
    //        len = 1;
    //        c++;
    //    }
    //}
    //arr_v[c] = len;
    //c++;
    //for (int i = 0; i < N; i++)
    //    cout << arr_v[i] << " ";

    //13д
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int arr_a[N], arr_b[N];
    //for (int i = 0; i < N; i++) {
    //    arr_a[i] = 0;
    //    arr_b[i] = 0;
    //}
    //int c_a, c_b;
    //c_a = c_b = 0;
    //for (int i = 0; i < N - 1; i++) {
    //    arr_a[0] = 0;
    //    if (arr[i] != arr[i + 1]) {
    //        c_a++;
    //        arr_b[c_b] = i;
    //        arr_a[c_a] = i + 1;
    //        c_b++;
    //    }
    //}
    //arr_b[c_b] = N - 1;
    //for (int i = 0; i < N; i++) {
    //    cout << arr_a[i] << " ";
    //}
    //cout << endl;
    //for (int i = 0; i < N; i++) {
    //    cout << arr_b[i] << " ";
    //}

    //13ж 
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int w[N];
    //if (arr[0] != arr[1])
    //    w[0] = arr[0];
    //else
    //    w[0] = 0;
    //for (int i = 1; i < N - 1; i++) {
    //    if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
    //        w[i] = arr[i];
    //    else
    //        w[i] = 0;
    //}
    //if (arr[N - 1] != arr[N - 2])
    //    w[N - 1] = arr[N - 1];
    //else
    //    w[N - 1] = 0;
    //for (int i = 0; i < N; i++)
    //    cout << w[i] << " ";

    //8a
    
    //int T1[N], T2[N];
    //cout << "Enter a subset T1: ";
    //for (int i = 0; i < N; i++)
    //    cin >> T1[i];
    //cout << "Enter a subset T2: ";
    //for (int i = 0; i < N; i++)
    //    cin >> T2[i];
    //int c = 0;
    //for (int i = 0; i < N; i++) 
    //    if (T1[i] == 1)
    //        c++;
    //cout << c;

    //8б
    
    //int T1[N], T2[N];
    //cout << "Enter a subset T1: ";
    //for (int i = 0; i < N; i++)
    //    cin >> T1[i];
    //cout << "Enter a subset T2: ";
    //for (int i = 0; i < N; i++)
    //    cin >> T2[i];
    //bool fl = true;
    //int c = 0;
    //for (int i = 0; i < N && fl == true; i++) {
    //    if (T1[i] == 1 && T2[i] == 0)
    //        fl = false;
    //    else if (T1[i] == T2[i])
    //        c++;
    //}
    //if (fl && c == N)
    //    cout << "T1 = T2";
    //else if (fl)
    //    cout << "true";
    //else
    //    cout << "false";

    //8в
    
    //int T1[N], T2[N];
    //cout << "Enter a subset T1: ";
    //for (int i = 0; i < N; i++)
    //    cin >> T1[i];
    //cout << "Enter a subset T2: ";
    //for (int i = 0; i < N; i++)
    //    cin >> T2[i];
    //int b1[N];
    //int b2[N];    
    //int b3[N];
    //for (int i = 0; i < N; i++) {
    //    if (T1[i] == 1 || T2[i] == 1)
    //        b1[i] = 1;
    //    else
    //        b1[i] = 0;
    //}
    //for (int i = 0; i < N; i++) {
    //    if (T1[i] == T2[i] && T2[i] == 1)
    //        b2[i] = 1;
    //    else
    //        b2[i] = 0;
    //}
    //for (int i = 0; i < N; i++) {
    //    if (T1[i] == 1 && T2[i] == 0)
    //        b3[i] = 1;
    //    else
    //        b3[i] = 0;
    //}
    //for (int i = 0; i < N; i++)
    //    cout << b1[i] << " ";
    //cout << endl;
    //for (int i = 0; i < N; i++)
    //    cout << b2[i] << " ";
    //cout << endl;
    //for (int i = 0; i < N; i++)
    //    cout << b3[i] << " ";
    //cout << endl;

    //15a

    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int s, t;
    //s = 1;
    //t = N;
    //int len = 1;
    //for (int i = 0; i < N - 1; i++) {
    //    if (arr[i] <= arr[i + 1])
    //        len++;
    //    else {
    //        if (s < len)
    //            s = len;
    //        if (t > len)
    //            t = len;
    //        len = 1;
    //    }    
    //}
    //if (s < len)
    //    s = len;
    //else if (t > len)
    //    t = len;
    //len = 1;
    //cout << "S = " << s << endl;
    //cout << "t = " << t << endl;
    
    //15б

    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int u[N];
    //for (int i = 0; i < N; i++)
    //    u[i] = 0;
    //int c = 0;
    //int len = 1;
    //for (int i = 0; i < N - 1; i++) {
    //    if (arr[i] <= arr[i + 1])
    //        len++;
    //    else {
    //        u[len - 1]++;
    //        len = 1;
    //    }
    //}
    //u[len - 1]++;
    //for (int i = 0; i < N; i++)
    //    cout << u[i] << " ";

    //    

    //бублсорт реализация  функцией

    //int arr[N];
    //for (int i = 0; i < N; i++) {
    //    cin >> arr[i];
    //}
    ////массив до сортировки
    //for (int i = 0; i < N; i++) {
    //    cout << arr[i] << " ";
    //}
    //cout << endl;
    //Buble_sort(arr);
    ////массив после сортировки
    //for (int i = 0; i < N; i++) {
    //    cout << arr[i] << " ";
    //}

    //реализация без функций

    // buble_sort
    //int arr[N];
    //for (int i = 0; i < N; i++) {
    //    cin >> arr[i];
    //}
    //bool fl = true;
    //for (int i = N; i != 0 && fl; i--) {
    //    fl = false;
    //    for (int j = 1; j < i; j++) {
    //        if (arr[j] < arr[j - 1]) {
    //            int t = arr[j];
    //            arr[j] = arr[j - 1];
    //            arr[j - 1] = t;
    //            fl = true;
    //        }
    //    }
    //}
    //for (int i = 0; i < N; i++) {
    //    cout << arr[i] << " ";
    //}
    //
    //shake_sort
    //int arr[N];
    //for (int i = 0; i < N; i++) {
    //    cin >> arr[i];
    //}
    //bool fl = true;
    //int left = 0;
    //int right = N - 1;
    //while (left < right && fl) {
    //    fl = false;
    //    for (int i = left; i < right; i++) {
    //        if (arr[i] > arr[i + 1]) {
    //            int t = arr[i];
    //            arr[i] = arr[i + 1];
    //            arr[i + 1] = t;
    //            fl = true;
    //        }
    //    }
    //    right--;
    //    for (int i = right; i > left; i--) {
    //        if (arr[i] < arr[i - 1]) {
    //            int t = arr[i];
    //            arr[i] = arr[i - 1];
    //            arr[i - 1] = t;
    //            fl = true;
    //        }
    //    }
    //    left++;
    //}
    //for (int i = 0; i < N; i++) {
    //    cout << arr[i] << " ";
    //}

    //22

    // с вспомогательным массивом
    //int arr[N];
    //int new_arr[N];
    //int left = 0;
    //int right = N - 1;
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //for (int i = 0; i < N && left < right; i++) {
    //    if (arr[i] < 0) {
    //        new_arr[left] = arr[i];
    //        left++;
    //    }
    //    else {
    //        new_arr[right] = arr[i];
    //        right--;
    //    }
    //}
    //for (int i = 0; i < N; i++)
    //    cout << new_arr[i] << " ";
    // 
    // без вспомогательного массива но в любом порядке
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int l = 0;
    //int r = N - 1;
    //while (l <= r) {
    //    while (arr[l] < 0)
    //        l++;
    //    while (arr[r] >= 0)
    //        r--;
    //    if (l <= r) {
    //        int t = arr[l];
    //        arr[l] = arr[r];
    //        arr[r] = t;
    //        r--;
    //        l++;
    //    }
    //}
    //for (int i = 0; i < N; i++)
    //    cout << arr[i] << " ";
    //
    // без доп массива и сохраняя порядок
    //int arr[N];
    //int j;
    //bool fl = false;
    //int k;
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //for (int i = 0; i < N && !fl; i++) {
    //    fl = true;
    //    while (arr[i] <= 0)
    //        i++;
    //    j = i;
    //    for (; j < N && arr[j] > 0; j++);
    //    if (j != N) {
    //        k = j - 1;
    //        fl = false;
    //        while (k >= i) {
    //            int t = arr[k + 1];
    //            arr[k + 1] = arr[k];
    //            arr[k] = t;
    //            k--;
    //        }
    //    }
    //}
    //for (int i = 0; i < N; i++)
    //    cout << arr[i] << " ";

    // Слияние массивов

    //int arr1[5] = { 2, 6, 8, 9, 13 };
    //int arr2[5] = { 1, 3, 4, 15, 19 };
    //int res[10];
    //slianie(arr1, arr2, res);
    //for (int i = 0; i < N*2; i++)
    //    cout << res[i] << " ";

    // все элемнты массива = 1
    
    //int arr[10] = { 1,1,1,1,1,1,1,1,1,1 };
    //bool fl = true;
    //for (int i = 0; i < 10 && fl; i++)
    //    if (arr[i] != 1)
    //        fl = false;
    //if (fl)
    //    cout << "YES";
    //else
    //    cout << "NO";

    // найдется эл равный данному

    //int n;
    //cout << "n = ";
    //cin >> n;
    //int arr[11] = { 1,2,3,4,5,6,7,8,9, 10 };
    //bool fl = false;
    //for (int i = 0; i < 10 && !fl; i++) {
    //    if (arr[i] == n)
    //        fl = true;
    //}
    //if (fl)
    //    cout << "YES";
    //else
    //    cout << "NO";

    // равны ли 2 вектора

    //int arr1[N], arr2[N];
    //cout << "first Massive: ";
    //for (int i = 0; i < N; i++)
    //    cin >> arr1[i];
    //cout << "Second Massive: ";
    //for (int i = 0; i < N; i++)
    //    cin >> arr2[i];
    //bool fl = true;
    //for (int i = 0; i < N  && fl; i++)
    //    if (arr1[i] != arr2[i])
    //        fl = false;
    //if (fl)
    //    cout << "YES";
    //else
    //    cout << "NO";

    //22в

    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //bool fl_ubiv = true;
    //bool fl_vozr = true;
    //for (int i = 1; i < N && (fl_ubiv || fl_vozr); i++) {
    //    if (arr[i] >= arr[i - 1])
    //        fl_ubiv = false;
    //    if (arr[i] <= arr[i - 1])
    //        fl_vozr = false;
    //}
    //if (fl_ubiv || fl_vozr)
    //    cout << "YES";
    //else
    //    cout << "NO";

    //22г
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //bool fl = false;
    //for (int i = 0; i < N && !fl; i++)
    //    for (int j = i; j < N && !fl; j++)
    //        if (arr[i] == arr[j])
    //            fl = true;
    //if (fl)
    //    cout << "YES";
    //else
    //    cout << "NO";

    // есть ли unique  элементы

    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //bool fl = false;
    //for (int i = 0; i < N && !fl; i++) {
    //    bool fl2 = true;
    //    for (int j = 0; j < N && fl2; j++) {
    //        if (i != j)
    //            if (arr[j] != arr[i])
    //                fl2 = false;
    //    }
    //    if (!fl2)
    //        fl = true;
    //}
    //if (fl)
    //    cout << "YES";
    //else
    //    cout << "NO";

    //22 д 
    
    //int arr[N];
    //for (int i = 0; i < N; i++)
    //    cin >> arr[i];
    //int c = 0;
    //for (int i = 0; i < N; i++) {
    //    bool fl2 = true;
    //    for (int j = 0; j < N && fl2; j++) {
    //        if (i != j)
    //            if (arr[j] == arr[i])
    //                fl2 = false;
    //    }
    //    if (fl2)
    //        c++;
    //}
    //cout << c;

    // пересечение массивов
    
    //int arr1[N], arr2[N], ans[N*2];
    //ifstream inputFile("INPUT.txt");
    //ofstream outText("OUTPUT.txt");
    //if (!inputFile) {
    //    cout << "ERROR" << endl;
    //    return 1;
    //}
    //for (int i = 0; i < N; i++) 
    //    inputFile >> arr1[i];
    //for (int i = 0; i < N; i++) 
    //    inputFile >> arr2[i];
    //int k = 0;
    //peresech_arr(arr1, arr2, ans, k);
    //for (int i = 0; i < k; i++) {
    //    cout << ans[i] << " ";
    //    outText << ans[i] << " "; 
    //}

    // разность массивов

    //int arr1[N], arr2[N], ans[N * 2];
    //ifstream in("INPUT.txt");
    //ofstream out("OUTPUT.txt");
    //if (!in) {
    //    cout << "ERROR" << endl;
    //        return 1;
    //}
    //for (int i = 0; i < N; i++)
    //    in >> arr1[i];
    //for (int i = 0; i < N; i++)
    //    in >> arr2[i];
    //int k = 0;
    //raznost_arr(arr1, arr2, ans, k);
    //for (int i = 0; i < k; i++) {
    //    cout << ans[i] << " ";
    //    out << ans[i] << " ";
    //}
    //in.close();
    //out.close();
    
    // сложение многочленов

    //int arr1[N], arr2[N], ans[N];
    //ifstream in("INPUT.txt");
    //ofstream out("OUTPUT.txt");
    //if (!in) {
    //    cout << "ERROR, bro";
    //    return 1;
    //}
    //for (int i = 0; i < N; i++)
    //    in >> arr1[i];
    //for (int i = 0; i < N; i++)
    //    in >> arr2[i];
    //sum_mn(arr1, arr2, ans);
    //for (int i = 0; i < N; i++) {
    //    cout << ans[i] << " ";
    //    out << ans[i] << " ";
    //}
    //in.close();
    //out.close();

    // умножение многочленов

    //int arr1[N], arr2[N];
    //int ans[2 * N - 1] = {0};
    //ifstream in("INPUT.txt");
    //ofstream out("OUTPUT.txt");
    //if (!in) {
    //    cout << "ERROR";
    //    return 1;
    //}
    //for (int i = 0; i < N; i++)
    //    in >> arr1[i];
    //for (int i = 0; i < N; i++)
    //    in >> arr2[i];
    //umn_mn(arr1, arr2, ans);
    //for (int i = 0; i < 2*N-1; i++) {
    //    cout << ans[i] << " ";
    //    out << ans[i] << " ";
    //}
    //in.close();
    //out.close();
    
    // взятие производной у многочлена

    //int arr[N], ans[N];
    //ifstream in("INPUT.txt");
    //ofstream out("OUTPUT.txt");
    //for (int i = 0; i < N; i++)
    //    in >> arr[i];
    //proizv(arr, ans);
    //for (int i = 0; i < N; i++) {
    //    cout << ans[i] << " ";
    //    out << ans[i] << " ";
    //}
    //in.close();
    //out.close();

    // схема горнера

    //int arr[N], dels[100];
    //ifstream in("INPUT.txt");
    //ofstream out("OUTPUT.txt");
    //int x;
    //for (int i = 0; i < N; i++)
    //    in >> arr[i];
    //int k = 0;
    //in >> x;
    //int ans = horner(x, arr);
    //out << ans;
    //return 0;

    //40а
    
    //int arr[N][N];
    //ofstream out("OUTPUT.txt");
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < N; j++) {
    //        arr[i][j] = 0;
    //    }
    //    arr[i][i]++;
    //}
    //out_matrix(arr, out);

    //out.close();

    //40б

    //int arr[N][N];
    //ofstream out("OUTPUT.txt"); 
    //triangle_matrix(arr);
    //out_matrix(arr, out);
    //out.close();

    //40в

    //int arr[N][N];
    //ofstream out("OUTPUT.txt");
    //make_null_matrix(arr);
    //for (int i = 0; i < N; i++) {
    //    int c = 1;
    //    for (int j = i; j < N; j++) {
    //        arr[i][j] = c;
    //        c++;
    //    }
    //}
    //out_matrix(arr, out);
    //out.close();

    //40г

    //int arr[N][N];
    //ofstream out("OUTPUT.txt");
    //int c = 2;
    //for (int i = 0; i < N; i++) {
    //    int k = c;
    //    for (int j = 0; j < N; j++) {
    //        arr[i][j] = k++;
    //    }
    //    c++;
    //}
    //out_matrix(arr, out);
    //out.close();

    //45

    //int arr[N][N];
    //ifstream in("INPUT.txt");
    //ofstream out("OUTPUT.txt");
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < N; j++) {
    //        in >> arr[j][i];
    //    }
    //}
    //out_matrix(arr, out);
    //in.close();
    //out.close();

    //39
    //int arr[N][N];
    //ifstream in("INPUT.txt");
    //ofstream out("OUTPUT.txt");
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < N; j++) {
    //        in >> arr[i][j];
    //    }
    //}
    //int sm = 0;
    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < N; j++) {
    //        sm += arr[i][j] * arr[i][j];
    //    }
    //}
    //double ans = sqrt(sm);
    //cout << ans;
    //out << ans;
    //in.close();
    //out.close();

    // нахождение макс элемента
    
    //int m, n;
    //cout << "Matrix m*n" << endl;
    //cout << "n = ";
    //cin >> n;
    //cout << "m = ";
    //cin >> m;
    //ifstream in("INPUT.txt");
    //int** arr = create_matrix(in, n, m);
    //show_matrix(arr, n, m); 
    //int ans = find_max(arr, n, m);
    //cout << endl << ans << endl;
    //for (int i = 0; i < n; i++) {
    //    delete[] arr[i];
    //}
    //delete[] arr;

    // Найти максимальный и минимальный элемент в матрице и переставить их местами. 
    //int m, n;
    //cout << "Matrix m*n" << endl;
    //cout << "n = ";
    //cin >> n;
    //cout << "m = ";
    //cin >> m;
    //ifstream in("INPUT.txt");
    //ofstream out("OUTPUT.txt");
    //int** arr = create_matrix(in, n, m);
    //swap_min_max(arr, n, m);
    //show_matrix(arr, n, m, out);

    //for (int i = 0; i < n; i++) {
    //    delete[] arr[i];
    //}
    //delete[] arr;

    // Найти максимальный и минимальный элемент в матрице и переставить местами столбцы, в которых они расположены. 

    //int n, m;
    //cout << "Matrix n*m" << endl;
    //cout << "n = ";
    //cin >> n;
    //cout << "m = ";
    //cin >> m;
    //ifstream in("INPUT.txt");
    //ofstream out("OUTPUT.txt");
    //int** arr = create_matrix(in, n, m);
    //swap_min_max_col(arr, n, m);
    //show_matrix(arr, n, m, out);
    //for (int i = 0; i < n; i++) 
    //    delete[] arr[i];
    //delete[] arr;
}

void swap_min_max_col(int** arr, int n, int m) {
    int mx = arr[0][0];
    int mx_col = 0;
    int mn = arr[0][0];
    int mn_col = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > mx) {
                mx = arr[i][j];
                mx_col = j;
            }
            if (arr[i][j] < mn) {
                mn = arr[i][j];
                mn_col = j;
            }

        }
    }
    if (mx_col != mn_col) {
        for (int i = 0; i < n; i++) {
            int t = arr[i][mx_col];
            arr[i][mx_col] = arr[i][mn_col];
            arr[i][mn_col] = t;
        }
    }
}


void swap_min_max(int** arr, int n, int m) {
    int mx = arr[0][0];
    int mx_id[2] = {0, 0};
    int mn = arr[0][0];
    int mn_id[2] = { 0, 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > mx) {
                mx = arr[i][j];
                mx_id[0] = i;
                mx_id[1] = j;
            }
            if (arr[i][j] < mn) {
                mn = arr[i][j];
                mn_id[0] = i;
                mn_id[1] = j;
            }
                
        }
    }
    int t = arr[mx_id[0]][mx_id[1]];
    arr[mx_id[0]][mx_id[1]] = arr[mn_id[0]][mn_id[1]];
    arr[mn_id[0]][mn_id[1]] = t;
}

int find_max(int** arr, int n, int m) {
    int mx = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > mx)
                mx = arr[i][j];
        }
    }
    return mx;
}

int** create_matrix(ifstream& in, int n, int m) {
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            in >> arr[i][j];
    return arr;
}

void show_matrix(int** arr, int n, int m, ofstream& out) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
            out << arr[i][j] << " ";
        }
        cout << endl;
        out << endl;
    }
}

void make_null_matrix(int arr[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }
}

void out_matrix(int arr[][N], ofstream& out) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
            out << arr[i][j] << " ";
        }
        cout << endl;
        out << endl;
    }
}

void triangle_matrix(int arr[][N]) {
    make_null_matrix(arr);
    for (int i = 0; i < N; i++) {
        int c = 1;
        for (int j = 0; j <= i; j++) {
            arr[i][j] = c;
            c++;
        }
    }
}

double horner(int x, int* arr) {
    double result = arr[0];

    for (int i = 1; i < N; i++) {
        result = result * x + arr[i];
    }

    return result;
}

bool is_simple(int x) {
    if (x == 2)
        return true;
    if (x < 2)
        return false;
    if (x % 2 == 0)
        return false;
    for (int i = 3; i <= ((x / 2) + 1); i += 2)
        if (x % i == 0)
            return false;
    return true;
}

void Buble_sort(int arr[]) {
    bool fl = true;
    for (int i = N; i != 0 && fl; i--) {
        fl = false;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[j - 1]) {
                int t = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
                fl = true;
            }
        }
    }
} // обменом 

void shake_sort(int* arr) {
    bool fl = true;
    int left = 0;
    int right = N - 1;
    while (left < right && fl) {
        fl = false;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
                fl = true;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                int t = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = t;
                fl = true;
            }
        }
        left++;
    }
}

void sort_with_max_po_vozr(int* arr) {
    for (int i = N - 1; i != 0; i--) {
        int mx_id = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] > arr[mx_id])
                mx_id = j;
        }
        if (mx_id != i) {
            int t = arr[i];
            arr[i] = arr[mx_id];
            arr[mx_id] = t;
        }

    }
}

void sort_with_min_po_vozr(int* arr) {
    for (int i = 0; i < N; i++) {
        int mn_id = i;
        for (int j = i; j < N; j++) {
            if (arr[j] < arr[mn_id])
                mn_id = j;
        }
        if (mn_id != i) {
            int t = arr[i];
            arr[i] = arr[mn_id];
            arr[mn_id] = t;
        }

    }
}

void sort_with_min_po_ubiv(int* arr) {
    for (int i = N - 1; i != 0; i--) {
        int mn_id = 0;
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[mn_id])
                mn_id = j;
        }
        if (mn_id != i) {
            int t = arr[i];
            arr[i] = arr[mn_id];
            arr[mn_id] = t;
        }

    }
}

void sort_with_max_po_ubiv(int* arr) {
    for (int i = 0; i < N; i++) {
        int mx_id = i;
        for (int j = i; j < N; j++) {
            if (arr[j] > arr[mx_id])
                mx_id = j;
        }
        if (mx_id != i) {
            int t = arr[i];
            arr[i] = arr[mx_id];
            arr[mx_id] = t;
        }

    }
}

void slianie(int* arr1, int* arr2, int* res) {
    int i, j;
    i = j = 0;
    int k = 0;
    while (i < N && j < N) {
        if (arr1[i] <= arr2[j]) {
            res[k] = arr1[i];
            i++;
        }
        else {
            res[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < N) {
        res[k] = arr1[i];
        i++;
        k++;
    }
    while (j < N) {
        res[k] = arr2[j];
        j++;
        k++;
    }
}

void sort_vstavkoi(int* arr) {
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int t = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = t;
        }
    }
}

void proizv(int arr[], int ans[]) {
    int k = 0;
    for (int i = N - 1; i >= 0; i--) {
        ans[k] = i * arr[k];
        k++;
    }
}

void umn_mn(int arr1[], int arr2[], int ans[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans[i + j] += arr1[i] * arr2[j];
        }
    }
}

void sum_mn(int arr1[], int arr2[], int ans[]) {
    for (int i = 0; i < N; i++)
        ans[i] = arr1[i] + arr2[i];

}

void raznost_arr(int arr1[], int arr2[], int ans[], int &k) {
    int i, j, t;
    i = j = 0;
    while (i < N && j < N) {
        if (arr1[i] < arr2[j]) {
            ans[k++] = arr1[i++];
        }
        else if (arr1[i] > arr2[j]) {
            j++;
        }
        else {
            i++;
            j++;
        }
        while (i > 0 && i < N && arr1[i] == arr1[i - 1]) i++;
        while (j > 0 && j < N && arr2[j] == arr2[j - 1]) j++;
    }
    while (i < N) {
        ans[k++] = arr1[i++];
        while (i > 0 && i < N && arr1[i] == arr1[i - 1]) i++;
    }
}

void peresech_arr(int arr1[], int arr2[], int ans[], int& k) {
    int i, j, t;
    i = j = 0;
    while (i < N && j < N) {
        if (arr1[i] < arr2[j]) i++;
        else if (arr1[i] > arr2[j]) j++;
        else {
            t = arr1[i];
            ans[k] = t;
            while (i < N && arr1[i] == t) i++;
            while (j < N && arr2[j] == t) j++;
            k++;
        }
    }
}
