= Vue.js の基本的な使い方

//lead{
ここでは Vue.js の基本的な使い方について簡単に書きます。

Vue.js の機能は多機能です。本稿では基本的なよく使うであろう機能を中心に解説していきます。
//}

== Vue インスタンスの作成

まずはじめにVueインスタンスを作成することからはじまります。Vueインスタンスは以下のように生成します。

//source[new.js]{
new Vue({
  // オプションを記述していく
  el: '#app',
  data: {
    count: 0
  },
  methods: {
    countup: function(){
      this.count++
    }
  }
})
//}

代表的なオプションは以下のようなものがあります。

 : el
    Vueインスタンスをマウントするセレクタを登録する
 : data
    Vueで管理するデータを登録する
 : methods
    dataを操作するメソッドを登録する

methods で登録されたメソッドはのちほど解説する v-on ディレクティブで呼び出すことが可能です。

== ライフサイクル

Vue.js を使用するにあたりインスタンスのライフサイクルを抑えておくと、インスタンスの初期化処理を行う際便利です。

Vue.js はインスタンスのライフサイクルごとに呼ばれるフックを提供しています。フックはVueインスタンスを作成する際渡す引数のオブジェクトに、以下のように関数を登録して使用していきます。

//source[hook.js]{
new Vue({
  created: function () {
    // ここはインスタンスが作際された後に呼ばれる
    console.log('created')
  }
})
//}

フックは @<img>{vue-lifecycle} のような順番で呼ばれていきます。

//image[vue-lifecycle][Vueインスタンスのライフサイクル]{
Vueのライフサイクル
//}

 : beforeCreate
    インスタンスが作成される前の処理
 : created
    インスタンスが作成された後の処理
 : beforeMount
    DOMにマウントされる前の処理
 : mounted
    DOMにマウントされた後の処理
 : beforeUpdate
    紐付けられたデータがアップデートされDOMが更新される前の処理
 : updated
    DOMが更新された後の処理
 : beforeDestroy
    インスタンスが削除される前の処理
 : destrpyed
    インスタンスが削除された後の処理

@<img>{vue-lifecycle} のタイミングで任意のコードを実行させることが可能です。例としては beforeMount で Ajaxでデータを取得するコードを書き、得られたデータをインスタンスにセットするといった使い方をすることが可能です。使わなくてもアプリケーションの開発を行うことはできますが、要件に応じて使えるように覚えておくと良いでしょう。

== リアクティブシステム

Vue.js は data プロパティに登録したオブジェクトに属するすべてのプロパティを Vue.js 内のリアクティブシステムに取り込みます。以下のコードでは count がリアクティブになります。

//source[new.js]{
var newInstance = new Vue({
  el: '#app',
  // data内のプロパティはすべてリアクティブになる
  data: {
    count: 0
  }
})
//}

data プロパティの count を表示したいときは以下のように書きます。

//source[template.html]{
<h1>Hello Vue !!</h1>
<div id="app">
  count:{{ count }}
</div>
//}

HTML 内に {{}} があります。これは "Mustache" 構文というもので、この中に書かれたプロパティの値を展開します。今回は count の値が表示されることになります。初期値は0なため、0と表示されます。

//image[reactive_01][データの表示]{
データの表示
//}

次に data の中の count を書き換えてみたいと思います。デベロッパーツールを開いて以下のコードを実行してみてください。

//source[increment.js]{
newInstance.$data.count++
//}

count がインクリメントされ、以下のように0から1に変わるはずです。

//image[reactive_02][インクリメントされたデータの表示]{
countがインクリメントされる
//}

このように count がリアクティブになり、値を変更することでビューに新しい値が反映されます。実際のアプリケーションではメソッドを介して data の中を書き換えていくことになります。

== ディレクティブ

ディレクティブは v- から始まる Vue.js で使用する特殊な属性です。主に data プロパティに登録したオブジェクトの値が変化した際、リアクティブに DOM に対して変化を加える効果があります。例としては条件分岐を行うことのできる v-if 、データの繰り返し表示に使用する v-for 、イベントリスナをアタッチするための v-on 、などがあります。

=== 条件分岐

Vue.js で値による条件分岐で DOM の表示非表示を操作したい時、使用できるディレクティブとして v-if と v-show が存在します。v-if と v-show の違いとしては、v-if は DOM から消してしまいますが、v-show は display 属性を none にするだけで DOM には存在するという違いがあります。また、v-if は v-else-if や v-else のように複数の条件に対応することができます。

v-show を試してみます。以下のようなコードを書いてみます。

//source[v-show.js]{
new Vue({
  el: '#app',
  data: {
    showFlg: false
  }
})
//}

//source[template.html]{
<h1>Hello Vue !!</h1>
<div id="app">
  <div v-show="showFlg">
    表示されないけどDOMにいる
  </div>
</div>
//}

このコードを実行すると@<img>{v-show}のように DOM には描画されますが、display が none になり、見かけ上は表示されていないのですが DOM 上には存在するようになります。

//image[v-show][v-showではDOMに描画されるがdisplayがnoneになる]{
v-showの図
//}

v-if を試してみます。以下のようなコードを書いてみます。

//source[v-if.js]{
new Vue({
  el: '#app',
  data: {
    showFlg: false
  }
})
//}

//source[template.html]{
<h1>Hello Vue !!</h1>
<div id="app">
  <div v-if="showFlg">
    表示されない
  </div>
  <div v-else>
    表示される
  </div>
</div>
//}

このコードを実行すると@<img>{v-if}のように DOM に描画されません。

//image[v-if][v-ifではDOMに描画されない]{
v-ifの図
//}

以上のように表示に関する条件分岐は二種類の方法で実現できます。要件に応じて DOM に残す必要があるか検討し使用していくのがよいです。

=== 繰り返し

=== イベントリスナ

== フォーム

== コンポーネント

== props
