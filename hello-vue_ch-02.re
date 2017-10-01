= Vue.jsのはじめかた

早速 Vue.js を使い始めたいと考えたとき、どのようにはじめれば良いでしょうか？本章では Vue.js の始め方について書いていきます。

== CDNを使う

簡単に Vue.js を試すには CDN を利用するのが良いです。CDN は unpkg@<fn>{unpkg}  を利用すると script タグで以下のように読み込みます。

//emlist[][html]{
<script src="https://unpkg.com/vue"></script>
//}

はじめはこのように簡単に読み込んで Vue.js の機能を試すのが楽で良いです。

== npm install する

ある程度慣れてきたら npm もしくは yan をもちいて環境を構築してみると良いです。

== vue-cliを使う

npm や yarn を使って環境構築をするのが煩わしくなってきた場合、vue-cli を使用するとよいでしょう。

vue-cli は Vue.js を使ったプロジェクトの scaffolding するコマンドラインツールです。

== Railsで使う

もし Rails を使って Webアプリケーションを構築するのであれば、webpacker を利用するのが Rails の流儀に則った開発が出来るのでお薦めです。

== Lalabelで使う

//footnote[unpkg][UNPKG：https://unpkg.com/]
