姓名：鐘民憲
學號：b06901017
系級：電機一

Compiler:C++11
IDE:Dev-c++ 5.11

※Purpose of these cpps and txts:
1.Generate_input_x.cpp is used to generate input_x.txt.
2.Generate_input_y.cpp is used to generate input_y.txt.
3.Generate_model.cpp is used to generate model.txt.
4.input_x.txt is the training datas used to represent the possibilities of tic_tac_toe board.
5.input_y.txt is the training datas that teach nueral network which step to take when encountering the situations in input_x.
6.model.txt describes the structure of neural network.
7.model_out.txt is the neural network after training.
8.model2.txt有個小地方與model.txt不同，但不知為何勝率比model.txt還高，所以放在上傳檔案中
9.model2_out.txt是沒有train的model2(所以跟model2一樣)

※How to compile and execute:
1.Put hw6.cpp into HW06_b069001017 folder.
2.Open hw6.cpp and set up the parameters.
  (1)For model, I set learning rate 0.01, epoch 10, and batch size 100.(win rate 92%~93%)
  (2)For model2, 我發現我把epoch設為0(完全沒train)，跑出來就會有逼近95%勝率，然後train過之後勝率就會下降，我也不知道為什麼會這樣
3.Compile and run.

※How did I generate training data?
1.For input_x:
我先把棋盤3^9種可能性全部列出來，然後刪掉所有不可能的情況：場上圈圈與叉叉數量不一樣多(因為player叉叉先手)、死局(有人已經連線了)
然後再不需要給的盤面也刪掉，如：棋盤只剩一個空格以及必輸的情況(圈圈有雙活二而叉叉沒任何活二)
剩下的就是所有neural network需要會下的盤面了
2.For input_y:
我的想法是根據所有input_x中的情況，去決定如果是我的話會下在什麼地方
如果盤面我方有任何活二，那當然就直接把它連起來
然而如果敵方有一個活二而我方一個都沒有的時候，當然就一定要把敵方擋住
接著，如果上述情況都沒有發生，而我方有地方是可以製造雙活二的，那當然就要下在那裏，這樣下一回合就可以獲勝
最後，若上述條件都不成立，沒有立即的勝負攸關時，我把它分成有九個空格、七個空格跟其他三種狀況去討論，因為遊戲剛開始的盤面可能性較少，故我想用窮舉就可以搞定
當有九個空格，也就是一開始的時候，我選擇下在中間，雖然下在角落也不是不行，但一開始下在中間比較不會讓敵方有活二的機會，而且考量到neural network不會完全按照我給的input_y去下棋，所以選擇和局率比較高，但勝率相對較低的中間下法，以免neural network一步走錯就輸掉遊戲
當有七個空格時(圈叉各下一子)，我直接用if-else去窮舉所有情況，有必勝或高勝率下法就下那邊，沒有的話就下中間
其他的情況由於變數太多，所以我選擇用老師上課教的評估函數(heuristic)去決定下在哪一個位置，雖然我沒有一一檢查，不過我相信它下得大概跟我會做的選擇八九不離十

最後我的training data一共有2085筆

※How did I disign neural network?
我的構想：(靈感來自評估函數)
第一層，先將input層的One-hot encoding轉換成1(x)、0.75(o)、0(-)
第二層，分別把橫列、直行、對角線的xo-加起來(所以x跟o越多，數字越大，且x的比重比o重)
output層，根據每一格會受到哪一橫列、哪一直行、哪一對角線的影響，把那些會影響的數都加起來(Ex：假設我們看左上角那格，那格會受到第一橫列、第一直行及左上右下斜角的影響)
之所以把x設為1，o設為0.75的原因，是因為優先度：x活二>o活二>一個x>...

然後model2是在做原本model時，不小心打錯了一個數字，所以神經元沒有照我想像的方式連接，沒想到跑出來的結果竟然比原model好，令我非常驚訝，而且不train就已經有超高勝率，真不知道是怎麼辦到的= =

~~~Appreciate TA for grading them~~~