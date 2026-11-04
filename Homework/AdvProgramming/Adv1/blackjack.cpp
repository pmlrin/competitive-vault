#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

#define LEN_OF_MAX_NAME 20

// 扑克牌面值枚举
typedef enum {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} RankType;

// 扑克牌花色枚举
typedef enum { CLUBS, DIAMONDS, HEARTS, SPADES } SuitType;

// 扑克牌结构体
struct Card {
    RankType rank;
    SuitType suit;
};

// 重载<<运算符
ostream &operator<<(ostream &outStream, const Card &card) {
    // 输出花色
    if (card.suit == CLUBS)
        outStream << "梅花";
    else if (card.suit == DIAMONDS)
        outStream << "方块";
    else if (card.suit == HEARTS)
        outStream << "红桃";
    else if (card.suit == SPADES)
        outStream << "黑桃";

    // 输出面值
    if (card.rank == ACE)
        outStream << "A";
    else if (card.rank == JACK)
        outStream << "J";
    else if (card.rank == QUEEN)
        outStream << "Q";
    else if (card.rank == KING)
        outStream << "K";
    else
        outStream << (int)card.rank;

    return outStream;
}

// 21点游戏类
class GameOf21Point {
  private:
    Card deck[52]; // 一副扑克牌
    int dealPos;   // 发牌位置
    Card hands
        [8]
        [21]; // hands[0]存储庄家手中的扑克牌，hands[1-7]存储各位玩家手中的扑克牌
    int numOfCard[8]; // 庄家(numOfCard[0])及玩家(numOfCard[1-7])手中的扑克牌数
    char name[8][LEN_OF_MAX_NAME]; // 庄家与玩家姓名
    int numOfPlayer;               // 玩家人数

    // 辅助函数
    void Shuffle();                            // 洗牌
    int GetTotalScore(Card hand[21], int num); // 返回一手扑克牌的总分值
    void ShowStatus(int num,
                    bool hideFirstCardAndTotalScore = false); // 显示状态
    Card DealOneCard();                                       // 发一张扑克牌

  public:
    GameOf21Point();          // 无参数的构造函数
    virtual ~GameOf21Point(); // 析构函数
    void Game();              // 运行游戏
};

// 构造函数
GameOf21Point::GameOf21Point() {
    dealPos = 0;
    numOfPlayer = 0;
    strcpy(name[0], "庄家");
    // 初始化牌组
    int index = 0;
    for (int s = CLUBS; s <= SPADES; s++) {
        for (int r = ACE; r <= KING; r++) {
            deck[index].suit = (SuitType)s;
            deck[index].rank = (RankType)r;
            index++;
        }
    }
}

// 析构函数
GameOf21Point::~GameOf21Point() {
    // 无需特殊清理
}

// 洗牌
void GameOf21Point::Shuffle() {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    dealPos = 0;
}

// 获取总分值
int GameOf21Point::GetTotalScore(Card hand[21], int num) {
    int score = 0;
    int aceCount = 0;
    for (int i = 0; i < num; i++) {
        if (hand[i].rank == ACE) {
            aceCount++;
            score += 11;
        } else if (hand[i].rank >= JACK) {
            score += 10;
        } else {
            score += (int)hand[i].rank;
        }
    }
    // 处理A
    while (score > 21 && aceCount > 0) {
        score -= 10;
        aceCount--;
    }
    return score;
}

// 显示状态
void GameOf21Point::ShowStatus(int num, bool hideFirstCardAndTotalScore) {
    cout << name[num] << "：";
    if (hideFirstCardAndTotalScore && num == 0) {
        cout << "<隐藏>";
        for (int i = 1; i < numOfCard[num]; i++) {
            cout << hands[num][i];
        }
    } else {
        for (int i = 0; i < numOfCard[num]; i++) {
            cout << hands[num][i];
        }
        if (!hideFirstCardAndTotalScore) {
            cout << " 总分值" << GetTotalScore(hands[num], numOfCard[num]);
        }
    }
    cout << endl;
}

// 发一张牌
Card GameOf21Point::DealOneCard() { return deck[dealPos++]; }

// 运行游戏
void GameOf21Point::Game() {
    // 输入玩家人数和姓名
    cout << "多少人加入游戏?(1～7):";
    cin >> numOfPlayer;
    for (int i = 1; i <= numOfPlayer; i++) {
        cout << "输入第" << i << "位玩家的姓名:";
        cin >> name[i];
    }

    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        // 初始化
        for (int i = 0; i <= numOfPlayer; i++) {
            numOfCard[i] = 0;
        }
        Shuffle();

        // 发初始牌：每人两张
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j <= numOfPlayer; j++) {
                hands[j][numOfCard[j]++] = DealOneCard();
            }
        }

        cout << "游戏开始" << endl;

        // 显示状态，隐藏庄家第一张牌
        ShowStatus(0, true);
        for (int i = 1; i <= numOfPlayer; i++) {
            ShowStatus(i);
        }

        // 玩家决定是否要牌
        bool playerBust[8] = {false};
        for (int i = 1; i <= numOfPlayer; i++) {
            char choice;
            do {
                cout << name[i] << "，你想再要一张牌吗(y,n)?";
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    hands[i][numOfCard[i]++] = DealOneCard();
                    ShowStatus(i);
                    int score = GetTotalScore(hands[i], numOfCard[i]);
                    if (score > 21) {
                        cout << name[i] << "爆牌！" << endl;
                        playerBust[i] = true;
                        break;
                    }
                }
            } while (choice == 'y' || choice == 'Y');
        }

        // 显示庄家所有牌
        ShowStatus(0);

        // 庄家决定是否要牌（简单规则：小于17要牌）
        while (GetTotalScore(hands[0], numOfCard[0]) < 17) {
            cout << "庄家的点数为 " << GetTotalScore(hands[0], numOfCard[0])
                 << " (小于17)，要一张牌..." << endl;
            hands[0][numOfCard[0]++] = DealOneCard();
            ShowStatus(0);
        }
        int dealerScore = GetTotalScore(hands[0], numOfCard[0]);
        if (dealerScore > 21) {
            cout << "庄家爆牌！" << endl;
        }

        // 判断胜负
        for (int i = 1; i <= numOfPlayer; i++) {
            int playerScore = GetTotalScore(hands[i], numOfCard[i]);
            if (playerBust[i]) {
                cout << name[i] << "，对不起，你输了！" << endl;
            } else if (dealerScore > 21) {
                cout << name[i] << "，你赢了！" << endl;
            } else if (playerScore > dealerScore) {
                cout << name[i] << "，你赢了！" << endl;
            } else if (playerScore == dealerScore) {
                cout << name[i] << "，你打平局了！" << endl;
            } else {
                cout << name[i] << "，对不起，你输了！" << endl;
            }
        }

        cout << "你想再玩一次吗(y,n)?";
        cin >> playAgain;
    }
}

int main() {
    GameOf21Point game;
    game.Game();
    return 0;
}