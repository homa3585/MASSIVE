#include <iostream>

using namespace std;
int const N = 13;

bool is_simple(int x) {
    if (x == 2)
        return true;
    if (x < 2)
        return false;
    if (x % 2 == 0)
        return false;
    for (int i = 3; i <= ((x / 2) + 1); i+=2)
        if (x % i == 0)
            return false;
    return true;
}

//реализация сортировок функцией
// достаточно просто вызвать их и сам массив будет отсортирован
void Buble_sort(int* arr) {
    bool fl = true;
    for (int i = N; i != 0 && fl; i--) {
        fl = false;
        for (int j = 1; j < i ; j++) {
            if (arr[j] < arr[j - 1]) {
                int t = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
                fl = true;
            }
        }
    }
}

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

int main() {
    // дз 1a, 4а, 6, 11(a,b), 13(a)(e), 22(a)(b)(ж) 
    // 13 вгдж, (8aбв), 15аб
    // пузырьковая, шейкерная, 22з

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
    ////аналогично с shake_sort

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

}
