= Vue.jsのはじめかた

早速 Vue.js を使い始めたいと考えたとき、どのようにはじめれば良いでしょうか？本章では Vue.js の始め方について書いていきます。

== CDNを使う

簡単に Vue.js を試すには CDN を利用するのが良いです。CDN は unpkg@<fn>{unpkg}  を利用すると script タグで以下のように読み込みます。

//emlist[][html]{
<script src="https://unpkg.com/vue"></script>
//}

はじめはこのように簡単に読み込んで Vue.js の機能を試すのが楽で良いです。script タグで読み込むだけでは .vue ファイルによる単一ファイルコンポーネントの機能を使うことは出来ませんが、その分ビルドのためのスクリプトについて考える必要がないので Vue.js 自身の学習に集中することが出来るので、初めのうちはこちらをお薦めします。

== npm を利用して環境を構築する

ある程度慣れてきたら npm もしくは yarn を用いて環境を構築するのがよいです。npm や yarn などのパッケージ管理ツールを用いて Vue.js の開発環境を構築するには一般的にバンドルツールを用いて行うのが最近の主流となっています。

バンドルツールは Webpack や Browserify などを使うことが可能です。それぞれのバンドルツールごとに Webpack は vue-loader、Browserify は vueify といったプラグインがあります。これらのプラグインは Vue.js の強力な機能である単一ファイルコンポーネントを利用するときに必要になります。

単一ファイルコンポーネントを用いると template script style の三つがセットになったコンポーネント単位のファイルを作ることが可能になります。マークアップと動作がセットになったファイルは、複数のページで共通して使用する部品などを作る際にとても便利です。

このように npm などを利用して開発環境を構築することで、Vue.js の強力な機能を使い開発を行うことが出来ます。

== vue-cliを利用して環境を構築する

npm や yarn を使って環境構築をする際、ビルドスクリプトやビルドのための設定を作らなくてはならないため、スクリプトの作成に追われ本質的なアプリケーション開発になかなか入れないことにフラストレーションを感じるかも知れません。そういう場合は vue-cli の使用を検討すると良いでしょう。

vue-cli は Vue.js を使ったプロジェクトの scaffolding をするコマンドラインツールです。引数にテンプレート名を与えることでそのテンプレートを使用してプロジェクトのひな形を作ることが出来ます。

コマンドは以下のようにして実行することにより、プロジェクトを作成できます。

//cmd{
$ @<b>{vue init テンプレート名 プロジェクト名}
//}

プロジェクト名で指定した名前のディレクトリが作成され、テンプレート名で指定されたテンプレートでプロジェクトが作成されます。

オフィシャルなテンプレートは@<table>{vue-cli-template}があります。

//table[vue-cli-template][vue-cliのオフィシャルテンプレート]{
テンプレート名	詳細
-------------------------------------------------------------
webpack	フルセットのWebpackテンプレート。ホットリロード、lint、テストなどの設定がフルに入っている。
webpack-simple	必要最小限のWebpackテンプレート。最低限ビルドが出来る設定が入っている。
browserify	フルセットのBrowserifyテンプレート。ホットリロード、lint、テストなどの設定がフルに入っている。
browserify-simple	必要最小限のBrowserifyテンプレート。最低限ビルドが出来る設定が入っている。
pwa	PWAのアプリケーションを作るためのテンプレート。webpackをベースにしている。
simple	scriptファイルでCDNの Vue.js を読み込むHTMLファイルを作るだけのテンプレート。
//}

webpack などのフルセットのテンプレートを利用するのはある程度慣れてからのほうが良いです。初心者であれば webpack-simple などで最小限のビルドの設定を使い拡張していくのが良いでしょう。ホットリロードやlint等についてある程度詳しいのであればフルセットを利用し開発をはじめると本質的なアプリケーション開発にすぐに入ることが出来るのでお薦めです。

== Ruby on Railsで使う

もし Ruby on Rails を使って Webアプリケーションを構築するのであれば、webpacker を利用するのが Rails のレールに乗った開発が出来るのでお薦めです。

//footnote[unpkg][UNPKG：https://unpkg.com/]
