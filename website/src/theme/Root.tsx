import { CssBaseline, ThemeProvider } from "@mui/material";
import { ReactNode } from "react";
import { TABTheme } from "../components/theme";
import React from "react";

export default function Root({ children }: { children: ReactNode[] }) {
  return <ThemeProvider theme={TABTheme}>
    <CssBaseline/>
    {children}
    </ThemeProvider>;
}
