= Vue.jsことはじめ

近年 JavaScript 界隈では React をはじめとするフレームワークの登場により、直接 DOM を jQuery で操作し動的な画面を作るという手法が古典的になりつつあります。

本稿では数ある JavaScript のフレームワークの内の一つ、Vue.js に焦点を当て簡単な使い方から、アプリケーションへの応用、Vue.js に関連するライブラリ、vue-router や vuex についてご紹介したいと思います。

本稿の対象者は Vue.js を触ったことのない初心者を想定しています。

== Vue.js とは?

Vue.js とはインタラクティブ性のあるユーザインタフェースを構築するための JavaScript のフレームワークです。

Vue.js は Evan You（https://github.com/yyx990803）さんの個人プロジェクトとして2013年に開発が開始され、2015年10月に 1.0、2016年10月に 2.0 がリリースされ、現在（2017年10月）最新のバージョンは 2.4.4 となっています。Evan さんは現在フルタイムで Vue.js を開発しており、開発の支援も様々な企業や個人スポンサーから受けているためほぼ万全の体制での開発が出来ている状態と言えます。

Vue.js の機能的な特徴としては MVVM（Model-View-ViewModel）のソフトウェアアーキテクチャパターンの影響を受けていることです。データとDOMがフレームワークによって紐付けられることにより、データに変更があればリアクティブに DOM の描画を変更できるという特徴があります。

またコンポーネント指向の開発もサポートされており、機能ごとにパーツを分解でき保守性高いコードを書くことが可能です。

== Progressive Framework

Vue.js の特徴として、Progressive Framework という概念を押し出しているということがあります。

Progressive Framework とは Evan さんが提唱した概念で、簡単に言えば要求に応じて追随していくことのできるフレームワークです@<fn>{progressive-framework}。

たとえば、まずはじめにリアクティブな仕組みを使ってフォームを作りデータを送る要求のみ満たすために Vue.js を使うとします。これだけならば単に script タグで Vue.js を読み込み、HTML に直接ディレクティブ（ Vue.js の為にタグに追加する属性）を書くだけで十分です。

その次に form を使い回したいという要求が出てきたとき、Vue.js のコンポーネントの機能を使用することで満たすことが出来ます。巣のままのコードでコンポーネントを使用すると見づらいというときは .vue ファイルに分割し、各種バンドルツールに応じた Vue の plugin を利用することでファイルの分割とビルドの仕組みを構築することが出来ます。

その次に SPA などのより「アプリケーション」らしいものにしていきたいと考えたとき、vue-router や vuex などの plugin を使用し要求を満たしていくことになります。

以上のように Vue.js とそれを取り巻く plugin などのエコシステムは、簡単な Web ページから Web アプリケーションまで様々な要求に対応することが可能です。plugin は主要なものは Evans さんによりは公式なサポートが行われているため、連携も自然に出来るようになっており安心感をもって導入できるというのもありがたいところです。

== コミュニティ

コミュニティ活動は各国で活発に行われており、特に2017年6月にポーランドで行われた VueConf@<fn>{vue-conf} は Vue.js の開発コアメンバーが勢揃いし大変な盛り上がりを見せました。

日本のコミュニティとしては Vue.js 日本ユーザーグループ@<fn>{vue-japan}が存在し、Slack を通じて活発な情報交換が行われています。ドキュメントの和訳などはここで参加者を募っており、 vue-loader や サーバサイドレンダリングガイド、nuxt.js などのプロジェクトのドキュメントの和訳がここで提起されリリースに至っています。

Vue.js を用いていてもし不明な点があれば公式フォーラム@<fn>{vue-forum}を利用することで解答を得られます。日本語のカテゴリでは日本語で質問することが可能です。

== 派生プロジェクト

===[column] Vue.jsのバージョンごとのコードネーム

Vue.js の面白い要素の一つとして、マイナーバージョンごとに映画やアニメのタイトルが使われていることです。

順番通りなら次は L になります。次のバージョンのコードネームを推測するのも Vue.js を愉しむ一つの要素となっています。

//table{
バージョン	コードネーム
-------------------------------------------------------------
v2.4.0	Kill la Kill
v2.3.0	JoJo's Bizarre Adventure
v2.2.0	Initial D
v2.1.0	Hunter X Hunter
v2.0.0	Ghost in the Shell
v1.0.0	Evangelion
v0.12.0	Dragon Ball
v0.11.0	Cowboy Bebop
v0.9.0	Animatrix
//}

===[/column]

//footnote[progressive-framework][Progressive framework：https://docs.google.com/presentation/d/1WnYsxRMiNEArT3xz7xXHdKeH1C-jT92VxmptghJb5Es/edit?usp=sharing]
//footnote[vue-conf][VueConf：https://conf.vuejs.org/]
//footnote[vue-japan][Vue.js 日本ユーザグループ：https://github.com/vuejs-jp/home]
//footnote[vue-forum][Vue.js 公式フォーラム：https://forum.vuejs.org/]
