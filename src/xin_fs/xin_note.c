

#include <lib/stdiox.h>
#include <xin_fs/xin.c>
#include <lib/memory.h>
#include <lib/exit_process.h>
#include <lib/string.h>

#define VGA_SCREEN_RESOLUTION 4480

void xin_note(char* file_name)
{
    clearScr();
    no_enter = true;
    arrows_navigate = true;


    xin_entry* xin_file = xin_find_entry(file_name);
    
    if(xin_file == nullptr)
    {
        xprintf("%zno such file or directory %s\n",set_output_color(red,white),program_parameters);
        
        while(1)
        {
            if(keyboard_scan_code == ENTER)
            {
                arrows_navigate = false;
                exit_process();
            }
        }   
    
    }
        
    else
    {
    
            
        if(xin_file->entry_type == XIN_DIRECTORY)
        {
            xprintf("%zyou cant edit directory\n",set_output_color(red,white));
            xprintf("%zuse F4 key to exit\n",set_output_color(red,white));
            while(keyboard_scan_code != ENTER);
            exit_process();
        }


        //for(uint8_t* xin_pointer_table = (uint8_t*)(XIN_POINTER_TABLE + xin_entry->starting_sector); *xin_pointer_table != XIN_EOF; xin_pointer_table++)
        
        char* data_pointer;

        {
            for(char* i = (char*)(xin_file->starting_sector * SECTOR_SIZE);  i < (char*)(xin_file->starting_sector + VGA_SCREEN_RESOLUTION); i++)
            {
                putchar(*i);
            }
        }


        cursor = (uint16_t*)(VGA_TEXT_MEMORY);
        
        while(keyboard_scan_code != F4_KEY);

        uint32_t file_data_counter = 0x0;

        data_pointer = (char*)(xin_file->starting_sector * SECTOR_SIZE);

        for(char* i = (char*)VGA_TEXT_MEMORY; 
                (uint32_t)i < VGA_TEXT_MEMORY + VGA_SCREEN_RESOLUTION; i+=2)
                if(*i == '\0')
                    *i = 0x20;

        for(char* i = (char*)VGA_TEXT_MEMORY; 
                (uint32_t)i < VGA_TEXT_MEMORY + VGA_SCREEN_RESOLUTION; i+=2, file_data_counter++)
                data_pointer[file_data_counter] = *i;

        xin_file->entry_size = file_data_counter;


    }

    
    exit_process();
}