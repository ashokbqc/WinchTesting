#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
SingleMotor* CommandBase::motor = NULL;
OI* CommandBase::oi = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem.reset(new ExampleSubsystem());
	winch.reset(new Winch(WINCH_PDP_PORT, WINCH_CAN_ID));
	motor = new SingleMotor();
	oi = new OI();
}
