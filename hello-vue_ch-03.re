= Vue.jsの基本的な使い方

//lead{
ここでは Vue.js の基本的な使い方について簡単に書きます。

Vue.js の機能は多機能です。本稿では基本的なよく使うであろう機能を中心に解説していきます。
//}

== Vue インスタンスの作成

まずはじめに Vue インスタンスを作成することからはじまります。Vue インスタンスは以下のように生成します。

//source[new.js][javascript]{
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

methods で登録されたメソッドはのちほど解説する @<ttb>{v-on} ディレクティブで呼び出すことが可能です。

== ライフサイクル

Vue.js を使用するにあたりインスタンスのライフサイクルを抑えておくと、インスタンスの初期化処理を行う際便利です。

Vue.js はインスタンスのライフサイクルごとに呼ばれるフックを提供しています。フックはVueインスタンスを作成する際渡す引数のオブジェクトに、以下のように関数を登録して使用していきます。

//source[hook.js][javascript]{
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

//source[new.js][javascript]{
var newInstance = new Vue({
  el: '#app',
  // data内のプロパティはすべてリアクティブになる
  data: {
    count: 0
  }
})
//}

data プロパティの count を表示したいときは以下のように書きます。

//source[template.html][html]{
<h1>Hello Vue !!</h1>
<div id="app">
  count:{{ count }}
</div>
//}

HTML 内に {{}} があります。これは @<ttb>{Mustache} 構文というもので、この中に書かれたプロパティの値を展開します。今回は count の値が表示されることになります。初期値は0なため、0と表示されます。

//image[reactive_01][データの表示]{
データの表示
//}

次に data の中の count を書き換えてみたいと思います。デベロッパーツールを開いて以下のコードを実行してみてください。

//source[increment.js][javascript]{
newInstance.$data.count++
//}

count がインクリメントされ、以下のように0から1に変わるはずです。

//image[reactive_02][インクリメントされたデータの表示]{
countがインクリメントされる
//}

このように count がリアクティブになり、値を変更することでビューに新しい値が反映されます。実際のアプリケーションではメソッドを介して data の中を書き換えていくことになります。

== ディレクティブ

ディレクティブは v- から始まる Vue.js で使用する特殊な属性です。主に data プロパティに登録したオブジェクトの値が変化した際、リアクティブに DOM に対して変化を加える効果があります。例としては条件分岐を行うことのできる @<ttb>{v-if} 、データの繰り返し表示に使用する @<ttb>{v-for} 、イベントリスナをアタッチするための @<ttb>{v-on} 、などがあります。

=== 条件分岐

値による条件分岐で DOM の表示非表示を操作したい時、使用できるディレクティブとして @<ttb>{v-if} と @<ttb>{v-show} が存在します。@<ttb>{v-if} と @<ttb>{v-show} の違いとしては、@<ttb>{v-if} は DOM から消してしまいますが、@<ttb>{v-show} は display 属性を none にするだけで DOM には存在するという違いがあります。また、@<ttb>{v-if} は @<ttb>{v-else-if} や @<ttb>{v-else} のように複数の条件に対応することができます。

書式はそれぞれ以下のように書きます。

//emlist[][]{
v-if="dataプロパティに登録しているオブジェクトのキー"
v-show="dataプロパティに登録しているオブジェクトのキー"
//}

v-show を試してみます。以下のようなコードを書いてみます。

//source[v-show.js][javascript]{
new Vue({
  el: '#app',
  data: {
    showFlg: false
  }
})
//}

//source[template.html][html]{
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

//source[v-if.js][javascript]{
new Vue({
  el: '#app',
  data: {
    showFlg: false
  }
})
//}

//source[template.html][html]{
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

=== リスト表示

リスト表示を行いたいときは @<ttb>{v-for} を使用します。@<ttb>{v-for} は他のディレクティブと違い""の中の値は特殊な文法で書いていきます。

書式は以下のように書きます

//emlist[][]{
v-for="変数名 in dataプロパティに登録しているオブジェクトのキー"
//}

リスト表示は以下のようなコードで行います。

//source[template.html][html]{
<ul v-for="item in items">
  <li>
    {{ item }}
  </li>
</ul>
//}

"item in items" は "item of items" と書くことも可能です。items に入れるオブジェクトは Array・Object・number・string の4種類です。それぞれのオブジェクトを使用する例を以下のように書きます。

//source[v-if.js][javascript]{
new Vue({
  el: '#app',
  data: {
  	array: [ "kongo", "hiei", "haruna", "kirishima" ],
    object: {
    	"hoge": "hogehoge",
      "fuga": "fugafuga"
    },
    number: 10,
    string: "Lorem"
  }
})
//}

//source[template.html][html]{
<h1>Hello Vue !!</h1>
<div id="app">
  <h2>
    array
  </h2>
  <ul v-for="(item, index) in array">
    <li>
      {{ item }} - {{ index }}
    </li>
  </ul>
  <h2>
    Object
  </h2>
  </h2>
  <ul v-for="(val, key, index) in object">
    <li>
      {{ val }} - {{ key }} - {{ index }}
    </li>
  </ul>
  <h2>
    number
  </h2>
  <ul v-for="(num, index) in number">
    <li>
      {{ num }} - {{ index }}
    </li>
  </ul>
  <h2>
    string
  </h2>
  <ul v-for="(char, index) in string">
    <li>
      {{ char }} - {{ index }}
    </li>
  </ul>
</div>
//}

表示結果を以下のようになります。

//image[v-for_01][Array][scale=0.5]{
Array
//}

//image[v-for_02][Object][scale=0.5]{
Object
//}

//image[v-for_03][number][scale=0.5]{
number
//}

//image[v-for_04][string][scale=0.5]{
string
//}

このように様々なオブジェクトに対してリスト表示を行うことが可能です。よく使用するのは主に配列に対するリスト表示だと思われます。配列に対して追加や削除を行うとそれに応じてリストは再レンダリングされます。

配列に対して行うことのできる操作は以下です。

 : push()
    配列の最後に要素の追加
 : pop()
    配列の最後を取得
 : shift()
    配列の最初の要素を取得
 : unshift()
    配列の最初に１個以上の要素を追加
 : splice()
    複数の要素を追加・削除
 : sort()
    配列を並び替える
 : reverse()
    配列を逆転する

Vue.js の data プロパティの配下は Vue.js によって変更メソッドがラップされているため、先程示した関数などで変更を行うとリアクティブに DOM が書き換えられます。通常の配列の操作ではインデックスで直接要素を指定し上書きすることができますが、その操作はでは Vue.js が変更を検出できないため、リアクティブに DOM が書き換わることがありません。配列に操作を加える際は上記のメソッドを介して行いましょう。

リスト表示の部分は Vue.js の事情により複雑です。ガイド@<fn>{list-guide}を参照して開発を行いましょう。

=== イベントリスナ

DOM に対してクリックやホバーを検出したい場合、@<ttb>{v-on} を使うことでイベント発火時に任意のメソッドを実行することが可能です。書式としては以下のようにディレクティブを書くことで実現します。

//emlist[][]{
v-on:イベント名="行いたい処理"
//省略記法
@イベント名="行いたい処理"
//}

簡単な例では以下のように書くと DOM をクリックした際ダイアログを出すことができます。

//source[template.html][html]{
<div v-on:click="alert('hoge')">alert</div>
//}

"" の中に JavaScript コードを書くことができます。ですがこの例のように "" の中に書いていくスタイルでは複雑なコードを書きたい場合現実的ではありません。

その時は Vue インスタンスを作成する際 methods プロパティに登録したメソッドの名前を記入することで、その処理を実行することで対応します。簡単な例を以下に書きます。

//source[v-on.js][javascript]{
new Vue({
  el: '#app',
  methods: {
  	showAlert: function () {
    	alert('hoge')
    }
  }
})
//}

//source[template.html][html]{
<h1>Hello Vue !!</h1>
<div id="app">
  <div v-on:click="showAlert">
    alert
  </div>
</div>
//}

このように書くと methods 内の showAlert メソッドが実行されます。動作は先ほどのコード例と同じ動作をします。

また methods 内のメソッドで data プロパティに登録されているオブジェクトは this を介して参照することができるので、参照したデータの操作を行い、DOM をリアクティブに書き換え、動的なアプリケーションの開発を行うことができます。

以下のコードは data プロパティに登録されているオブジェクトを更新して表示する例です。

//source[increment.js][javascript]{
new Vue({
  el: '#app',
  data: {
    count: 0
  },
  methods: {
  	increment: function () {
    	this.count += 1
    }
  }
})
//}

//source[template.html][html]{
<h1>Hello Vue !!</h1>
<div id="app">
  <div v-on:click="increment">
    increment
  </div>
  {{ count }}
</div>
//}

increment と表示された部分をクリックすることで、data プロパティ内の count が更新され、数値がインクリメントされていくのがわかると思います。

//image[v-on][incrementをクリックすると数値が更新されていく]{
increment
//}

== フォーム

== コンポーネント

== props

//footnote[list-guide][公式ガイド リストレンダリング：https://jp.vuejs.org/v2/guide/list.html]
