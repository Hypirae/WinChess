#pragma once

#include "stdafx.h"

namespace Chess
{
	class Terminal
	{
	public:
		wincon::console_out term;

		Terminal ();

		void drawBoard ( Board board );
	private:
		wincon::console_out_context _octx;
	};
}
