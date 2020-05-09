#pragma once

#include "../libafanasy/user.h"

#include "itemnode.h"

class ListNodes;

class ItemUser : public ItemNode
{
public:
	ItemUser(ListNodes * i_list_nodes, af::User * i_user, const CtrlSortFilter * i_ctrl_sf);
	~ItemUser();

	void v_updateValues(af::Node * i_afnode, int i_msgType);

	int errors_avoidhost;
	int errors_tasksamehost;
	int errors_retries;
	int errors_forgivetime;
	int jobs_lifetime;
	int max_running_tasks;
	int max_running_tasks_per_host;
	QString hostsmask;
	QString hostsmask_exclude;

	QString hostname;
	int jobs_num;
	int running_tasks_num;
	int64_t running_capacity_total;

	int64_t time_register;
	int64_t time_activity;

	void v_setSortType(   int i_type1, int i_type2 );
	void v_setFilterType( int i_type );

	bool calcHeight();

protected:
	virtual void v_paint(QPainter * i_painter, const QRect & i_rect, const QStyleOptionViewItem & i_option) const;

private:
	void updateInfo(af::User * i_user);

private:
	static const int HeightUser;

	QString strLeftBottom;
	QString strLeftTop;
	QString strHCenterTop;
	QString strRightTop;
	QString strRightBottom;
};
