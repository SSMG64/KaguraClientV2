
#include <time.h>
#include <sysutil/sysutil_msgdialog.h>

namespace Dialog
{
	bool Finished = false;
	bool YESNO = false;

	enum {
		MODE_IDLE = 0,
		MODE_ERRORCODE_DIALOG_TEST,
		MODE_STRING_OK,
		MODE_STRING_YESNO,
		MODE_STRING_DIALOG_3,
		MODE_STRING_DIALOG_4,
		MODE_STRING_DIALOG_5,
		MODE_CHECK_PROGRESSBAR_1,
		MODE_RUNNING,
		MODE_CHECK_TIMEOUT,
		MODE_TIMEOUT_NEXT,
		MODE_EXIT
	};

	static int msgdialog_mode = MODE_IDLE;

	static void cb_dialogText1(int button_type, void *userdata)
	{
		switch (button_type) {

		case CELL_MSGDIALOG_BUTTON_OK:
			msgdialog_mode = MODE_EXIT;
			break;
		case CELL_MSGDIALOG_BUTTON_ESCAPE:
			msgdialog_mode = MODE_EXIT;
			break;

		default:
			msgdialog_mode = MODE_EXIT;
			break;
		}
	}
	void ProgressBar(const char* msg, const char* Secondmessage, int DisplayInSeconds)
	{
		unsigned int type = CELL_MSGDIALOG_TYPE_SE_TYPE_NORMAL
			| CELL_MSGDIALOG_TYPE_BUTTON_TYPE_NONE
			| CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON
			| CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_NONE
			| CELL_MSGDIALOG_TYPE_PROGRESSBAR_SINGLE;
		cellMsgDialogOpen2(type, msg, NULL, NULL, NULL);
		cellMsgDialogProgressBarSetMsg(CELL_MSGDIALOG_PROGRESSBAR_INDEX_DOUBLE_UPPER, Secondmessage);
		cellMsgDialogProgressBarInc(CELL_MSGDIALOG_PROGRESSBAR_INDEX_SINGLE, 100);
		cellMsgDialogClose(DisplayInSeconds * 1000);
	}
	static void cb_dialogText2(int button_type, void *userdata)
	{
		switch (button_type) {

		case CELL_MSGDIALOG_BUTTON_YES:
			YESNO = true;
			msgdialog_mode = MODE_EXIT;
			Finished = true;
			break;

		case CELL_MSGDIALOG_BUTTON_NO:
			msgdialog_mode = MODE_EXIT;
			Finished = true;
			break;

		case CELL_MSGDIALOG_BUTTON_ESCAPE:
			msgdialog_mode = MODE_EXIT;
			Finished = true;
			break;

		default:
			break;
		}
	}


	void ShowYESNO(char* msg)
	{
		unsigned int type = CELL_MSGDIALOG_TYPE_SE_TYPE_NORMAL
			| CELL_MSGDIALOG_TYPE_BG_INVISIBLE
			| CELL_MSGDIALOG_TYPE_BUTTON_TYPE_YESNO
			| CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON
			| CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_YES;


		switch (msgdialog_mode)
		{
		case MODE_IDLE:
			break;

		case MODE_STRING_YESNO:
			cellMsgDialogOpen2(type, msg, cb_dialogText2, NULL, NULL);
			msgdialog_mode = MODE_RUNNING;
			break;

		case MODE_EXIT:
			cellMsgDialogClose((float)1);
			break;

		default:
			break;

		}


	}
	void Show(char* msg)
	{

		unsigned int type = CELL_MSGDIALOG_TYPE_SE_TYPE_ERROR
			| CELL_MSGDIALOG_TYPE_BG_INVISIBLE
			| CELL_MSGDIALOG_TYPE_BUTTON_TYPE_OK
			| CELL_MSGDIALOG_TYPE_DISABLE_CANCEL_ON
			| CELL_MSGDIALOG_TYPE_DEFAULT_CURSOR_OK;


		switch (msgdialog_mode)
		{
		case MODE_IDLE:
			break;

		case MODE_STRING_OK:
			cellMsgDialogOpen2(type, msg, cb_dialogText1, NULL, NULL);
			msgdialog_mode = MODE_EXIT;
			break;

		case MODE_EXIT:
			cellMsgDialogClose((float)5);
			break;

		default:
			break;

		}

		while (Dialog::msgdialog_mode != Dialog::MODE_EXIT){}  //wait for the dialog to end :P
	}

	void End()
	{
		Finished = false;
		YESNO = false;
	}


}
