// FinalGraphicDoc.h : CFinalGraphicDoc 类的接口
//

#pragma once
#include "DrawSet.h"
#include "FontSet.h"
#include "SeriGraph.h"


class CFinalGraphicDoc : public CDocument
{
protected: // 仅从序列化创建
	CFinalGraphicDoc();
	DECLARE_DYNCREATE(CFinalGraphicDoc)
// 属性
public:
	int m_nCheckedId;				//记录选中图形的标号
	bool m_bIsChecked;              //标记是否进入选中模式
	bool m_bIsSelected;             //标记是否选择上了图形         
	bool m_bEnablePaste;            //标记是否可以粘贴(仅在复制后可以)
	CPoint m_ptNow;                 //当前鼠标所在位置
	int nOldWidth;                  //前一次选中图形的宽度
	COLORREF crOldColor;			//前一次选中图形的画笔颜色
	CSeriGraph oldSeriGraph;        //当前复制图形的相关信息
	const CSeriGraph m_DefaultSet;  //默认参数设置，用来给其他对象初始化
	CSeriGraph m_SeriGraph;         //当前相关信息
	CList<CSeriGraph,CSeriGraph&> m_lGraph;   //序列化存储
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();          //新建
	virtual void Serialize(CArchive& ar);  //序列化

// 实现
public:
	virtual ~CFinalGraphicDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


