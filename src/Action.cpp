#include "Action.h"

using namespace safebox;
Action *Action::action_ = nullptr;
/**
 * @details
 *
 */
Action::Action(Prototype *prototype = nullptr) : prototype_(prototype)
{
}

/**
 * @details
 *
 */
Action::~Action(void){
	delete this->prototype_;
}

Action *Action::getInstance(Prototype *prototype)
{
  if(action_ == nullptr){
    action_ = new Action(prototype);
  }
  return action_;
}

/**
 * @details
 *
 */
void Action::setPrototype(Prototype *prototype)
{
	delete this->prototype_;
	this->prototype_=prototype;
}

/**
 * @details
 *
 */
void Action::run(void)
{
	prototype_->run();
}
