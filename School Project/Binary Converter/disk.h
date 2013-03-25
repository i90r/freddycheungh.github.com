#include <cstring>
#include "segment.h"
class disk{
		/*private*/
		segment* segm;	//Segment object
		char mode[2];	//Mode will store the mode ('a' or 'w')
		int seg_init, max_seg;	//seg_init stands for segment_initialized, max_seg stands for maximun segments

	public:
		disk();		//default constructor
		disk(int num_of_segments, const char* mode);
		const char* get_mode() const;
		segment get_segment(int pos) const;
		int get_segment_count() const;
		const segment* get_all_segments()const;
		int access(const char fname[]);
		void operator+=(const segment&);
		void operator=(const disk&);
		disk(const disk&);	//copy constructor
		~disk();		//destructor
};
