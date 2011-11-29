/*
	Copyright (c) 2011, T. Kroes <t.kroes@tudelft.nl>
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	- Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
	- Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
	- Neither the name of the TU Delft nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "vtkErCoreDll.h"

#include <vtkBorderRepresentation.h>
#include <vtkCameraInterpolator.h>
#include <vtkCallbackCommand.h>
#include <vtkObjectFactory.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkCamera.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper2D.h>
#include <vtkProperty2D.h>
#include <vtkActor2D.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkPropCollection.h>
#include <vtkWindow.h>
#include <vtkViewport.h>

class VTK_ER_CORE_EXPORT vtkErCameraRepresentation : public vtkBorderRepresentation
{
public:
	vtkTypeMacro(vtkErCameraRepresentation, vtkBorderRepresentation);
	static vtkErCameraRepresentation *New();

	void SetCamera(vtkCamera *camera);
	vtkGetObjectMacro(Camera,vtkCamera);

	virtual void GetActors2D(vtkPropCollection*);
	virtual void ReleaseGraphicsResources(vtkWindow*);
	virtual int RenderOverlay(vtkViewport*);
	virtual int RenderOpaqueGeometry(vtkViewport*);
	virtual int RenderTranslucentPolygonalGeometry(vtkViewport*);
	virtual int HasTranslucentPolygonalGeometry();
  
	virtual void BuildRepresentation();

protected:
	vtkErCameraRepresentation();
	~vtkErCameraRepresentation();

	// the camera and the interpolator
	vtkCamera             *Camera;

	// representation of the camera
	vtkPoints                  *Points;
	vtkPolyData                *PolyData;
	vtkTransformPolyDataFilter *TransformFilter;
	vtkPolyDataMapper2D        *Mapper;
	vtkProperty2D              *Property;
	vtkActor2D                 *Actor;

private:
	vtkErCameraRepresentation(const vtkErCameraRepresentation&);
	void operator=(const vtkErCameraRepresentation&);
};
