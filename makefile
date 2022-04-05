platformEntrance:  Platform.o Admin.o  User.o  Order.o  Goods.o  SQL.o  Calculator.o Platform.h Admin.h  User.h  Order.h  Goods.h  SQL.h  Calculator.h platformEntrance.h platformEntrance.o
	g++ Platform.o Admin.o  User.o  Order.o  Goods.o  SQL.o  Calculator.o Platform.h Admin.h  User.h  Order.h  Goods.h  SQL.h  Calculator.h platformEntrance.h platformEntrance.o  -o  platformEntrance
platformEntrance.o : platformEntrance.cpp
	g++ -c platformEntrance.cpp -o platformEntrance.o

Platform.o : Platform.cpp
	g++ -c Platform.cpp -o Platform.o

Admin.o : Admin.cpp
	g++ -c Admin.cpp -o Admin.o

User.o : User.cpp
	g++ -c User.cpp -o User.o

Order.o : Order.cpp
	g++ -c Order.cpp -o Order.o

Goods.o : Goods.cpp
	g++ -c Goods.cpp -o Goods.o

SQL.o : SQL.cpp
	g++ -c SQL.cpp -o SQL.o

Calculator.o : Calculator.cpp
	g++ -c Calculator.cpp -o Calculator.o

clean:
	rm *.o
	rm main