#property strict
string BotName = "Div Test";
int Magic = 1234;
double LotsToTrade = 0.10;
double StopLoss = -3700;
double ProfitTarget = 280.00;
int maxTrades = 1000;
int OnInit()
{
	return(INIT_SUCCEEDED);
}
void OnDeinit(const int reason)
{}
void OnTick()
{
	double Bollinger_2_Upper = iBands(NULL, 0, 34, 2.0, 0, PRICE_CLOSE, MODE_UPPER, 0);
	double Bollinger_2_Lower = iBands(NULL, 0, 34, 2.0, 0, PRICE_CLOSE, MODE_LOWER, 0);
	double Bollinger_25_Upper = iBands(NULL, 0, 34, 2.5, 0, PRICE_CLOSE, MODE_UPPER, 0);
	double Bollinger_25_Lower = iBands(NULL, 0, 34, 2.5, 0, PRICE_CLOSE, MODE_LOWER, 0);
	double Bollinger_Base = iBands(NULL, 0, 34, 0, 0, PRICE_CLOSE, MODE_MAIN, 0);
	double Bollinger_15_Upper = iBands(NULL, 0, 34, 2.0, 0, PRICE_CLOSE, MODE_UPPER, 0);
	double RSI = iRSI(NULL, 0, 13, PRICE_CLOSE, 0);
	double RSI_prev_High = iRSI(NULL, 0, 13, PRICE_HIGH, 1);
	double Bollinger_2_Upper_Shift15 = iBands(NULL, 0, 34, 2.0, 0, PRICE_CLOSE, MODE_UPPER,
		15);
	double Bollinger_2_Lower_Shift15 = iBands(NULL, 0, 34, 2.0, 0, PRICE_CLOSE, MODE_LOWER,
		15);
	double LastBid = MarketInfo(0, MODE_BID);
	double LastAsk = MarketInfo(0, MODE_ASK);
	double DiffPips = MathAbs(NormalizeDouble(Bollinger_2_Upper - Bollinger_2_Lower, Digits) /
		Point);
	double DiffPips_Shift_15 = MathAbs(NormalizeDouble(Bollinger_2_Upper_Shift15 -
		Bollinger_2_Lower_Shift15, Digits) / Point);
	int Lowest_index = iLowest(0, PERIOD_CURRENT, MODE_LOW, 5, 0);
	int prev_high_index = iHighest(0, PERIOD_CURRENT, MODE_HIGH, 5, 5);
	double Lowest_value = iLow(0, PERIOD_CURRENT, Lowest_index);
	double prev_high_value = iHigh(0, PERIOD_CURRENT, prev_high_index);
	/* Print("Current bar for CURRENT_PAIR H1: ",iTime(0,PERIOD_CURRENT,0),", ", iOpen(0,PERIOD_CURRENT,iHigh(0,PERIOD_CURRENT,0),", ", iLow(0,PERIOD_CURRENT,0),", iClose(0,PERIOD_CURRENT,0),", ", iVolume(0,PERIOD_CURRENT,iHighest(0, PERIOD_CURRENT, MODE_LOW, 10, 0),", ", iLowest(//====SELL====Above 2.0 Bollinger
	if (GetTotalOpenTrades() < maxTrades)
	{
	if (LastBid > Lowest_value &&
	Lowest_value < prev_high_value &&
	prev_high_value < LastBid &&
	prev_high_value >= Bollinger_2_Upper &&
	LastBid >= Bollinger_2_Upper &&
	DiffPips >= 150)
	{
	int OrderResult = OrderSend(Symbol(), OP_SELL, LotsToTrade, Bid, 10, 0, 0,
	"SELL Order", Magic, 0, clrRed);
	Print("Last Bid ="+LastBid);
	Page 1/2
	Print("Bollinger 2 Upper ="+Bollinger_2_Upper);
	Print("Prev High Value ="+prev_high_value);
	Print("Lowest Value="+Lowest_value);
	Print("Prev High Index="+prev_high_index);
	Print("Lowest index="+Lowest_index);
	}
	}
	}
	 Return the total number of open trades
	int GetTotalOpenTrades()
	{
	int TotalTrades = 0;
	 Loop through open orders and add them to TotalTrades
	for (int t=0; t <OrdersTotal(); t++)
	{
	if(OrderSelect(t, SELECT_BY_POS, MODE_TRADES))
	{
	if(OrderSymbol() != Symbol()) continue;
	if(OrderMagicNumber() != Magic) continue;
	if(OrderCloseTime() != 0) continue;
	TotalTrades = (TotalTrades +1);
	}
	}r
	eturn TotalTrades;
	}
	Page 2/2