#include <iostream>
#include <vector>
#include <format>
enum class OrderType {
	GoodTillCancel,
	FillandKill
};

enum class Side {
	Buy,
	Sell
};

using Price = std::int32_t;
using Quantity = std::uint32_t;
using OrderId = std::uint64_t;

struct LevelInfo {
	Price price;
	Quantity quantity;
};

using LevelInfos = std::vector<LevelInfo>;

class OrderbookLevelInfos {

	LevelInfos bids;
	LevelInfos asks;
	
	public:
	OrderbookLevelInfos(LevelInfos &bids, LevelInfos &asks){
		this->bids = bids;
		this->asks = asks;
	}
	LevelInfos getBids() {return bids;}
	LevelInfos getAsks() {return asks;}
	
};

class Order {

	OrderType orderType;
	OrderId orderid; 
	Side side; 
	Price price; 
	Quantity initialQuantity;
	Quantity remainingQuantity;

	public:
	Order(OrderType orderType, OrderId orderid, Side side, Price price, Quantity quantity){
		this->orderType = orderType;
		this->orderid = orderid;
		this->side = side;
		this->price = price;
		this->initialQuantity = quantity;
	}

	OrderType getOrderType() { return orderType; }
	OrderId getOrderId() { return orderid; }
	Side getSide() { return side; }
	Price getPrice() { return price; }
	Quantity getInitialQuantity() { return initialQuantity; }
	Quantity getRemainingQuantity() { return remainingQuantity; }
	Quantity getFilledQuantity() { return getInitialQuantity() - getRemainingQuantity(); }

	void fill(Quantity quantity){
		if(quantity > getRemainingQuantity()) throw std::logic_error(std::format("Order{()} cannot be filled more than its remaining quantity", getOrderId()));
		remainingQuantity = remainingQuantity - quantity;
	}
};