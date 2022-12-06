#include <stdio.h>

#define ELEMENT char

#define MAXSIZE 255
typedef struct {
    ELEMENT ch[MAXSIZE];
    int length;
} SString;

void initSString(SString &S) {
    for (char &i: S.ch) {
        i = '0';
    }
    S.length = 0;
}

int strLength(SString S) {
    return S.length;
}

bool insertString(SString &S, ELEMENT e) {
    S.ch[++S.length] = e;
    return true;
}

bool deleteString(SString &S, int i, ELEMENT &e) {
    if (i < 1 || i > S.length) {
        return false;
    }

    // 返回删除元素至e中
    e = S.ch[i];

    // 将第i个元素位置后的元素前移
    for (int j = i; j <= S.length; j++) {
        S.ch[j] = S.ch[j + 1];
    }

    //长度减一
    S.length--;
    return true;
}


void print(SString S) {
    for (int i = 1; i <= S.length; i++) {
        printf("%c", S.ch[i]);
    }
    printf("\n");
}


bool subString(SString &sub, SString S, int pos, int len) {
    if (pos + len - 1 > S.length) {
        return false;
    }

    for (int i = pos; i < pos + len; i++) {
        sub.ch[i - pos + 1] = S.ch[i];
    }
    sub.length = len;
    return true;

}

int strCompare(SString S, SString T) {
    for (int i = 0; i < S.length && T.length; ++i) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

//int index(SString S, SString T) {
//    int i = 1, n = strLength(S), m = strLength(T);
//    SString sub;
//    initSString(sub);
//    while (i <= n - m + 1) {
//        subString(sub, S, i, m);
//        if (strCompare(sub, T) != 0) {
//            ++i;
//        } else {
//            return i;
//        }
//    }
//    return 0;
//}

/**
 * 朴素模式
 */
int index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
        if (j > T.length) {
            return i - T.length;
        }
    }
    return 0;
}

/**
 * KMP算法
 */
int indexKMP(SString S, SString T,int next[]){
    int i=1,j=1;
    while (i<=S.length&&j<=T.length){
        if(j==0||S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        } else{
            j=next[j];
        }
    }
    if(j>T.length){
        return i-T.length;
    } else{
        return 0;
    }
}

int main() {
    SString S;
    initSString(S);
    insertString(S, 's');
    insertString(S, 'e');
    insertString(S, 'v');
    insertString(S, 'e');
    insertString(S, 'n');

    SString T;
    initSString(T);
    //insertString(T,'e');
    insertString(T, 'v');
    insertString(T, 'e');
    T.length = 1;
    //printf("%d", strLength(S));

    printf("%d", index(S, T));
    return 0;
}