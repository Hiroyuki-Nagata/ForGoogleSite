/**
 * WxTest.cpp - wxWidgetsの最小ソースコード
 * 
 * wxWidgets付属のminimal.cppから余分な部分を削除し、コメントを日本語に直しました
 * 
 * 2012/02/10 新規作成
 * https://sites.google.com/site/programmirovanienotes
 */

// ============================================================================
// 宣言
// ============================================================================

// ----------------------------------------------------------------------------
// ヘッダ
// ----------------------------------------------------------------------------
#include <wx/wx.h>

// 訳者注：プリコンパイルを考慮したコード・アイコン実装コードは省略

// 新しいアプリケーションの型を定義する、どのプログラムもwxAppから継承されるべ
// きである
class MyApp : public wxApp
{
public:
    // 基底クラスの仮想関数をオーバーライドする
    // ----------------------------

    // ここはアプリケーションの開始時に呼ばれ、アプリケーションの初期化に適した
    // 場所です。（ここで初期化を行なってコンストラクタにエラーがあればOnInit()
    // はfalseを返し、アプリケーションが終了します。）
    virtual bool OnInit();
};

// 新しいフレームの型を定義する、これはこのアプリケーションのメインフレームに
// なるでしょう
class MyFrame : public wxFrame
{
public:
    // コンストラクタ
    MyFrame(const wxString& title);

    // イベントハンドラ（これらの関数は仮想関数であるべきではない）
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:
    // wxWidgetsのイベントを処理するどんなクラスでもこのマクロは使わなければ
    // ならない
    DECLARE_EVENT_TABLE()
};

// ----------------------------------------------------------------------------
// 定数
// ----------------------------------------------------------------------------

// 操作のためのIDとメニューコマンド
enum
{
    // メニューの項目
    Minimal_Quit = wxID_EXIT,

    // "About"コマンドに応じたIDをアプリに持たせることは重要です。
    // この標準的な変数名はMacでは正しく動作しない
    // （というのはそれが特別なもので、"Apple"メニューの中に入っているからです）

    // 訳者注：MacでこのコードをコンパイルするにはApplicationBundleを考慮した
    // Makefileを用意する必要があるので注意
    Minimal_About = wxID_ABOUT
};

// ----------------------------------------------------------------------------
// イベントテーブルとwxWidgetsのためのその他のマクロ
// ----------------------------------------------------------------------------

// 以下のイベントテーブルは、イベントを処理するevent関数（イベントハンドラ）に
// よってwxWidgetsに紐付けられている。イベントの処理はアプリの使用時にも起こり
// うる、しかしこのような単純なメニューイベントはスタティックな関数のほうがより
// シンプルであろう。
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(Minimal_Quit,  MyFrame::OnQuit)
    EVT_MENU(Minimal_About, MyFrame::OnAbout)
END_EVENT_TABLE()

// 新しいアプリのオブジェクトを生成する：このマクロはwxWidgetsがプログラムの
// 実行時に、そのアプリのオブジェクトを作り出すことを許可する（これは多くの理由
// からスタティックなオブジェクトを使うよりも良い）そしてマクロが継承している
// アクセッサー関数であるwxGetApp()は正しい型への参照を返す（例えばMyAppであっ
// たりwxAppでは無かったり）
IMPLEMENT_APP(MyApp)

// ============================================================================
// 実装
// ============================================================================

// ----------------------------------------------------------------------------
// アプリケーションクラス
// ----------------------------------------------------------------------------

// 'メインプログラム'と同等のもの：つまりこのプログラムはここから”始まる”
bool MyApp::OnInit()
{
    // 基底クラスの初期化メソッドを呼ぶ。現在これはわずかなコマンドライン
    // オプションしか解釈できないが将来的にはもっといろいろなオプションを解釈
    // できるようになるだろう
    if ( !wxApp::OnInit() )
        return false;

    // メインのアプリケーションウィンドウを生成する
    MyFrame *frame = new MyFrame("Minimal wxWidgets App");

    // そしてそれを表示させる（フレームは、そのように簡単な操作ではないのだが、
    // 初期化しているときには現れない）
    frame->Show(true);

    // 成功時：wxApp::OnRun()が呼ばれるでしょう（それはメインのメッセージルー
    // プに入り、アプリケーションを稼働させる）。もしここでfalseが返ってくる
    // と、アプリケーションは即座に終了する
    return true;
}

// ----------------------------------------------------------------------------
// メインフレーム
// ----------------------------------------------------------------------------

// フレームのコンストラクタ
MyFrame::MyFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title)
{
    // 訳者注：アイコンは面倒なので削除

#if wxUSE_MENUS
    // メニューバーを設置
    wxMenu *fileMenu = new wxMenu;

    // ”About”の項目はヘルプメニューの下にあるべきでしょう
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(Minimal_About, "&About...\tF1", "Show about dialog");

    fileMenu->Append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program");

    // さあ新しく作成されたメニューをメニューバーに追加しましよう
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");

    // ... そしてフレームにこのメニューバーを設置する
    SetMenuBar(menuBar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // 慰みにステータスバーも作成してみる（デフォルトで１ペインのみね）
    CreateStatusBar(2);
    SetStatusText("Welcome to wxWidgets!");
#endif // wxUSE_STATUSBAR
}


// イベントハンドラ

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    // trueならば強制的にフレームを終了する
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format
                 (
                    "Welcome to %s!\n"
                    "\n"
                    "This is the minimal wxWidgets sample\n"
                    "running under %s.",
                    wxVERSION_STRING,
                    wxGetOsDescription()
                 ),
                 "About wxWidgets minimal sample",
                 wxOK | wxICON_INFORMATION,
                 this);
}
