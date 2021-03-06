/*
 * Advanced Simulation Library <http://asl.org.il>
 * 
 * Copyright 2015 Avtech Scientific <http://avtechscientific.com>
 *
 *
 * This file is part of Advanced Simulation Library (ASL).
 *
 * ASL is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, version 3 of the License.
 *
 * ASL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with ASL. If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef ACLVARIABLESP_H
#define ACLVARIABLESP_H

#include "../aclElementBase.h"
#include "../../aslUtilities.h"
#include "../aclUtilities.h"


namespace acl
{

	template <typename T> class VariableSP: public ElementBase
	{
		private:
			std::shared_ptr<T> value;
			string name;
			static const string prefix;
			static unsigned int id;
		public:
			explicit VariableSP(std::shared_ptr<T> v);
			virtual string str(const KernelConfiguration & kernelConfig) const;
			virtual string getName() const;
			virtual string getTypeSignature(const KernelConfiguration & kernelConfig) const;
			virtual string getLocalDeclaration(const KernelConfiguration & kernelConfig) const;
			virtual void addToKernelSource(vector<Element> & arguments,
			                               vector<Element> & localDeclarations) const;
			virtual void setAsArgument(cl::Kernel & kernel, unsigned int argumentIndex) const;
	};


	template <typename T> VariableSP<T>::VariableSP(std::shared_ptr<T> v):
		ElementBase(true, 0, typeToTypeID<T>()),
		value(v)
	{
		++id;
		name = prefix + asl::numToStr(id);
	}


	template <typename T> string VariableSP<T>::getName() const
	{
		return name;
	}


	template <typename T> string VariableSP<T>::str(const KernelConfiguration & kernelConfig) const
	{
		return name;
	}

	template <typename T> string VariableSP<T>::getLocalDeclaration(const KernelConfiguration & kernelConfig) const
	{
		return "";
	}


	template <typename T> void VariableSP<T>::addToKernelSource(vector<Element> & arguments,
	                                                            vector<Element> & localDeclarations) const
	{
	}

	template <typename T> void VariableSP<T>::setAsArgument(cl::Kernel & kernel,
	                                                        unsigned int argumentIndex) const
	{
		cl_int status = 0;		
		status = kernel.setArg(argumentIndex, *value);
		asl::errorMessage(status, "Kernel::setArg() - " + name + ", argument " + asl::numToStr(argumentIndex));
	}

		
} // namespace acl

#endif // ACLVARIABLE_H
