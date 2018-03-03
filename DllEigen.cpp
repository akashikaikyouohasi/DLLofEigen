// DllEigen.cpp : Defines the exported functions for the DLL application.
//


//#define EIGENFUNCS_EXPORTS

/*
EIGENFUNCS_EXPORTSの定義されていないプロジェクトで このヘッダーがインクルードされたときに明らかになります。
そのとき、EIGEN_FUNCS_APIイコール__declspec(dllimport)となり、 関数はインポートされるからです。
*/

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <Eigen/LU>
#include "EigenFuncs.h"



//Eigenの通すパスは、解答したフォルダの一番上。わざわざsrcを参照する必要はない。

/*
DLLはダイナミックリンクライブラリのこと。関数の共有ライブラリとして機能する実行ファイル。
メモリ内のDLLは複数のアプリからアクセス可能。
スタティックリンクライブラリは、各アプリケーションがビルドしてロードする必要がある。
異なる言語で書かれていても、関数の呼び出し規約に従う限り、使用することができる。

DLLにはエクスポートテーブルがある。エクスポートテーブルに記載されたエクスポート関数のみが、別の実行形式にアクセスが可能。
エクスポート方法は２つ：__stdcall規約を使うこと
（１）モジュール定義ファイル.defを作成し、それをもとにDLLをビルドする。
（２）関数の定義に、__declspec(dllexport)キーワードを使う。.defファイルは不要。



*/

/*
extern
複数ソースコードをまたいで変数やメソッドを使用するときに時に使います。
全ファイル中のどれかに定義されている 宣言だけを行い定義は行わない宣言方法です
*/
extern "C" {
	EIGEN_FUNCS_API void InverseMat(int dim, float a[], float ans[]) {
		/*
		逆行列を演算する関数
		[入力]
		dim:次元数
		a:行列の配列 dim×dim
		[出力]
		ans:計算した逆行列
		*/

		//dim次元の２次元行列作成
		Eigen::MatrixXf mat = Eigen::MatrixXf::Zero(dim, dim);

		//引数で与えられた配列を２次元行列に格納
		int count = 0;
		for (int c = 0; c < dim; c++) {
			for (int r = 0; r < dim; r++) {
				mat(c, r) = a[count];
				count++;
			}
		}

		//逆行列を計算
		//inverseは遅いらしい？
		Eigen::MatrixXf InvMat = mat.inverse();

		//計算した２次元逆行列を１次元配列に入れなおして返す
		count = 0;
		for (int c = 0; c < dim; c++) {
			for (int r = 0; r < dim; r++) {
				ans[count] = InvMat(c, r);
				count++;
			}
		}
	}
} // extern "C"