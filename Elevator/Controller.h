/**
 * \file Controller.h
 *
 * \author Siyan Ma
 *
 * \brief elevator controller derived class
 */

#pragma once
#include "ElevatorController.h"
#include "Floor.h"

/**
 * \brief elevator controller derived class
 */
class CController :
	public CElevatorController
{
public:
	CController();
	virtual ~CController();

	/** \brief Copy constructor disabled */
	CController(const CController &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CController &) = delete;

	/** \brief Initialize function 
	 * for testing project */
	void Initialize() {};
	virtual void Service() override;
	virtual void OnOpenPressed() override;
	virtual void OnClosePressed() override;
	virtual void OnPanelFloorPressed(int floor) override;
	virtual void OnCallUpPressed(int floor) override;
	virtual void OnCallDownPressed(int floor) override;

	/// The state machine states
	enum States { Idle, DoorOpening, DoorOpen, DoorClosing, Moving, Stop,
			FireModeOpen, FireModeClose, FireModeOpening, FireModeMoving,
			FireModeStop, FireModeClosing };

private:
	void SetState(States state);
	int WhatFloorToGoTo();
	int WhatFloorUp();
	int WhatFloorDown();

	int    mFloor = 1;      ///< The current floor
	States mState = Idle;   ///< The current state
	double mStateTime = 0;  ///< The time in a current state
	bool mGoingUp = true;	///< The moving directionn

	/// An object for each floor
	CFloor mFloors[NumFloors];
};

