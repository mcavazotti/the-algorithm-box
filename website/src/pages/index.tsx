import type { ReactNode } from "react";
import useDocusaurusContext from "@docusaurus/useDocusaurusContext";
import Layout from "@theme/Layout";

import { Box, Button, Container, Typography } from "@mui/material";
import Link from "@docusaurus/Link";
import React from "react";

export default function Home(): ReactNode {
  const { siteConfig } = useDocusaurusContext();
  return (
    <Layout title={siteConfig.title}>
      <Container sx={{ display: "flex", flexDirection: "column", alignItems: "center", paddingTop: 2 }}>
        <br/>
        <Typography variant="h4">Welcome to</Typography>
        <Box display="flex" flexDirection={{ xs: "column-reverse", md: "row" }} alignItems="center" gap={2}>
          <Box sx={{ textAlign: { xs: "center", md: "right" }, display: { xs: "flex", md: "initial" }, gap: 2 }}>
            <Typography variant="h2">The</Typography>
            <Typography variant="h2">Algorithm</Typography>
            <Typography variant="h2">Box</Typography>
          </Box>
          <Box component="img" src="img/Logo.png" height={{ xs: 200, md: 400 }} />
        </Box>
        <br />
        <Box display="flex" flexDirection={{ xs: "column", md: "row" }} alignItems="center" gap={4}>
          <Link href="/code">
            <Button variant="contained">Let's dive in!</Button>
          </Link>
          <Link href="/about">
            <Button variant="outlined">What is the Algorithm Box?</Button>
          </Link>
          <Link href="/whoami">
            <Button variant="outlined">Who am I?</Button>
          </Link>
        </Box>
      </Container>
    </Layout>
  );
}
