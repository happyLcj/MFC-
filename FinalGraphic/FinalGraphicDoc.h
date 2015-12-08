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
	COLORREF crOldColor;            
	int nOldWidth;
	const CSeriGraph m_DefaultSet;
	CSeriGraph m_SeriGraph;
	CList<CSeriGraph,CSeriGraph&> m_lGraph;
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

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


