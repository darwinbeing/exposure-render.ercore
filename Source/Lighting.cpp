
#include "Lighting.h"

void QLighting::ReadXML(QDomElement& Parent)
{
	/*
	// Intensity
	const float NormalizedIntensity = Parent.firstChildElement("NormalizedIntensity").attribute("Value").toFloat();
	m_Intensity = m_pTransferFunction->m_RangeMin + (m_pTransferFunction->m_Range * NormalizedIntensity);

	// Opacity
	const float NormalizedOpacity = Parent.firstChildElement("NormalizedOpacity").attribute("Value").toFloat();
	m_Opacity = NormalizedOpacity;

	QDomElement Kd = Parent.firstChildElement("Kd");

	m_Color.setRed(Kd.attribute("R").toInt());
	m_Color.setGreen(Kd.attribute("G").toInt());
	m_Color.setBlue(Kd.attribute("B").toInt());
	*/
}

void QLighting::WriteXML(QDomDocument& DOM, QDomElement& Parent)
{
	/*
	// Node
	QDomElement Node = DOM.createElement("Node");
	Parent.appendChild(Node);

	// Intensity
	QDomElement Intensity = DOM.createElement("NormalizedIntensity");
	const float NormalizedIntensity = GetNormalizedIntensity();
	Intensity.setAttribute("Value", NormalizedIntensity);
	Node.appendChild(Intensity);

	// Opacity
	QDomElement Opacity = DOM.createElement("NormalizedOpacity");
	const float NormalizedOpacity = GetNormalizedOpacity();
	Opacity.setAttribute("Value", NormalizedOpacity);
	Node.appendChild(Opacity);

	// Kd
	QDomElement Kd = DOM.createElement("Kd");
	Kd.setAttribute("R", m_Color.red());
	Kd.setAttribute("G", m_Color.green());
	Kd.setAttribute("B", m_Color.blue());
	Node.appendChild(Kd);

	// Kt
	QDomElement Kt = DOM.createElement("Kt");
	Kt.setAttribute("R", m_Color.red());
	Kt.setAttribute("G", m_Color.green());
	Kt.setAttribute("B", m_Color.blue());
	Node.appendChild(Kt);

	// Ks
	QDomElement Ks = DOM.createElement("Ks");
	Ks.setAttribute("R", m_Color.red());
	Ks.setAttribute("G", m_Color.green());
	Ks.setAttribute("B", m_Color.blue());
	Node.appendChild(Ks);
	*/
}